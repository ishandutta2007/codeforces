#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
template<typename T, typename U>
struct lazy_segment_tree{
    int n;
    int H;
    T base;
    vector<T> segtree;
    vector<U> lazytree;
    vector<bool> isempty;
    function<T(const T&, const T&)> join;
    function<T(int, const U&, const T&)> assign;
    function<U(const U&, const U&)> lazyassign;
    U deflazy;
    lazy_segment_tree(int n, function<T(int)> init, function<T(const T&, const T&)> join,function<T(int, const U&, const T&)> assign, function<U(const U&, const U&)> lazyassign, T defvalue, U delazy) : n(n), join(join), lazyassign(lazyassign), assign(assign), base(defvalue), deflazy(delazy){
        H = sizeof(int) * 8 - __builtin_clz(n);
        segtree.resize(2*n);
        lazytree.resize(n);
        isempty.resize(n,1);
        for(int i=0;i<n;i++){
            segtree[n+i]=init(i);
        }
        for(int i=n-1;i>=1;i--){
            segtree[i]=join(segtree[(i<<1)], segtree[(i<<1)|1]);
        }
    }
    void calc(int pos, int h){
        segtree[pos]=join(segtree[(pos<<1)],segtree[(pos<<1)|1]);
        if(!isempty[pos]){
            segtree[pos]=assign(h, lazytree[pos],segtree[pos]);
        }
    }
    void apply(int pos, U value, int h){
        segtree[pos]=assign(h, value, segtree[pos]);
        if(pos<n){
            lazytree[pos]=lazyassign(value, lazytree[pos]);
            isempty[pos]=0;
        }
    }
    void updatenode(int pos){
        int h=1;
        pos+=n;
        while(pos>1){
            h++;
            pos>>=1;
            calc(pos, h);
        }
    }
    void push(int pos){
        int h=H;
        int k=1<<(H-1);
        for(pos+=n;h;--h, k>>=1){
            int x=(pos>>h);
            if(x<n && !isempty[x]){
                apply((x<<1), lazytree[x], h);
                apply((x<<1)|1, lazytree[x], h);
                lazytree[x]=deflazy;
                isempty[x]=1;
            }
        }
    }
    void updaterange(int l, int r, U value){
        push(l);
        push(r-1);
        int k=1;
        int l0=l, r0=r;
        for(l+=n, r+=n;l<r;l>>=1, r>>=1, k++){
            if(l&1){
                apply(l++, value, k);
            }
            if(r&1){
                apply(--r, value,k);
            }
        }
        updatenode(l0);
        updatenode(r0-1);
    }
    T query(int l, int r){
        push(l);
        push(r-1);
        T ansl=base; 
        T ansr=base;
        for(l+=n, r+=n;l<r;l>>=1, r>>=1){
            if(l&1){
                ansl=join(ansl, segtree[l++]);
            }        
            if(r&1){
                ansr=join(segtree[--r], ansr);
            }
        }
        return join(ansl,ansr);
    }
    void printTree(){
        cout<<"SEGMENT TREE:\n";
        for(int i=0;i<2*n;i++){
            cout<<i<<": ";
            cout<<segtree[i]<<"\n";
        }
        cout<<"LAZY TREE:\n";
        for(int i=0;i<n;i++){
            cout<<i<<": ";
            cout<<lazytree[i]<<"\n";
        }
    }
};
void solve(){
    int n,k,m;
    cin>>n>>k>>m;
    lazy_segment_tree<ll,ll> colk(2*n + m, [](int x) ->ll{return x;}, [](const ll &x, const ll&y){return x>y ? x: y;}, [](int z,const ll &u, const ll &t){return u+t;}, [](const ll& x, const ll& y){return x+y;}, 0, 0);
    int ans = n;
    set<pair<int,int>> pawns;
    multiset<int> height;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        colk.updaterange(1, y + std::abs(x-k), pawns.count(mp(x,y)) ? -1 : 1);
        if(pawns.count(mp(x,y))){
            pawns.erase(mp(x,y));
            height.erase(height.find(y + std::abs(x-k)));
        }
        else{
            pawns.insert(mp(x,y));
            height.insert(y + std::abs(x-k));
        }
        if(pawns.empty()){
            cout<<"0\n";
            continue;
        }
        cout<<max(0ll, colk.query(0, *(--height.end())) - n)<<"\n";
        //colk.printTree();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}