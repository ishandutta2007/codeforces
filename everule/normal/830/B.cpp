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
template<typename T>
struct segment_tree{
    vector<T> segtree;
    int n;
    function<T(const T&, const T&)> join;
    T base;
    segment_tree(int n,function<T(const T&, const T&)> join, T defvalue) : n(n), join(join), base(defvalue){
        segtree.resize(2*n);
        for(int i=0;i<n;i++){
            segtree[n+i]=1;
        }
        for(int i=n-1;i>=1;i--){
            segtree[i]=join(segtree[2*i], segtree[2*i + 1]);
        }
    }
    void update(int pos, T val){
        pos+=n;
        segtree[pos]=val;
        pos>>=1;
        while(pos){
            segtree[pos]=join(segtree[2*pos],segtree[2*pos+1]);
            pos>>=1;
        }
    }
    T query(int x, int y){
        T ansl=base;
        T ansr=base;
        x+=n;
        y+=n+1;
        while(x<y){
            if(x&1){
                ansl=join(ansl, segtree[x++]);
            }
            if(y&1){
                ansr=join(segtree[--y], ansr);
            }
            x>>=1;
            y>>=1;
        }
        return join(ansl, ansr);
    }
};
const int MAXA = 100000;
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    vector<set<int>> pos(MAXA + 1);
    for(int i=0;i<n;i++){
        cin>>seq[i];
        pos[seq[i]].insert(i);
    }
    segment_tree<int> sum(n, [](const int &x,const int &y){return x+y;}, 0);
    int curr = 0;
    ll ans = 0;
    for(int i=0;i<=MAXA;i++){
        while(!pos[i].empty()){
            int idx = (pos[i].lower_bound(curr)!=pos[i].end()) ? *pos[i].lower_bound(curr) : *pos[i].begin();
            if(idx >= curr){
                ans+=sum.query(curr, idx);
                //cout<<curr<<" "<<idx<<" "<<ans<<"\n";
            }
            else{
                ans+=sum.query(curr, n-1) + sum.query(0, idx);
                //cout<<curr<<" "<<idx<<" "<<ans<<"\n";
            }
            curr = idx + 1==n ? 0 : idx + 1;
            sum.update(idx, 0);
            pos[i].erase(idx);
        } 
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}