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
    function<U(const U&,const U&)> lazyassign;

    lazy_segment_tree(vector<T> &seq, 
    function<T(const T&, const T&)> join, 
    function<T(int, const U&, const T&)> assign,
    function<U(const U&,const U&)> lazyassign,
    T base) : join(join), assign(assign), lazyassign(lazyassign), base(base){
        n = seq.size();
        H = 32 - __builtin_clz(n);
        segtree.resize(2*n);
        lazytree.resize(n);
        isempty.resize(n,1);
        for(int i=0;i<n;i++){
            segtree[n+i]=seq[i];
        }
        for(int i=n-1;i>=1;i--){
            segtree[i]=join(segtree[(i<<1)], segtree[(i<<1)|1]);
        }
    }

    lazy_segment_tree(int n, 
    function<T(const T&, const T&)> join, 
    function<T(int, const U&, const T&)> assign,
    function<U(const U&,const U&)> lazyassign,
    T base) : join(join), assign(assign), lazyassign(lazyassign), base(base), n(n){
        H = 32 - __builtin_clz(n);
        segtree.resize(2*n, base);
        lazytree.resize(n);
        isempty.resize(n,1);
    }
    void calc(int pos, int h){
        segtree[pos]=join(segtree[(pos<<1)],segtree[(pos<<1)|1]);
        if(!isempty[pos]){
            segtree[pos]=assign(h,lazytree[pos],segtree[pos]);
        }
    }
    void apply(int pos, U value, int h){
        segtree[pos]=assign(h, value, segtree[pos]);
        if(pos<n){
            if(!isempty[pos]){
                lazytree[pos]=lazyassign(value, lazytree[pos]);
            }
            else{
                lazytree[pos] = value;
            }
            isempty[pos]=0;
        }
    }
    void updatenode(int pos){
        int h=0;
        pos+=n;
        while(pos>1){
            h++;
            pos>>=1;
            calc(pos, h);
        }
    }
    void push(int pos){
        int h=H;
        for(pos+=n;h;--h){
            int x=(pos>>h);
            if(!isempty[x]){
                apply((x<<1), lazytree[x], h-1);
                apply((x<<1)|1, lazytree[x], h-1);
                isempty[x]=1;
            }
        }
    }
    void updaterange(int l, int r, U value){
        //cout<<"u "<<l<<" "<<r<<" "<<value<<"\n";
        if(l > r) return;
        push(l);
        push(r);
        int k=0;
        int l0=l, r0=r;
        for(l+=n, r+=n+1;l<r;l>>=1, r>>=1, k++){
            if(l&1){
                apply(l++, value, k);
            }
            if(r&1){
                apply(--r, value,k);
            }
        }
        updatenode(l0);
        updatenode(r0);
    }
    T query(int l, int r){
        //cout<<"q "<<l<<" "<<r<<"\n";
        if(l > r) return base;
        push(l);
        push(r);
        T ansl=base;
        T ansr=base;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
            if(l&1){
                ansl=join(ansl, segtree[l++]);
            }        
            if(r&1){
                ansr=join(segtree[--r], ansr);
            }
        }
        return join(ansl,ansr);
    }
};
const int INF = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    int ans1 = 1;
    for(int i=1;i<n;i++) ans1 += (seq[i] != seq[i-1]);
    lazy_segment_tree<int,int> st(n + 1, [&](int x,int y){
        return min(x,y);
    },
    [&](int h,int x,int y){
        return x + y;
    }, [&](int x,int y){
        return x + y;
    }, 2 * INF);
    st.updaterange(0,0,-2 * INF+1);
    st.updaterange(1, n, -INF);
    for(int i=1;i<n;i++){
        int l1 = st.query(0,seq[i]-1) + 1;
        int l2 = st.query(seq[i] + 1, n) + 1;
        int lm = st.query(seq[i], seq[i]);
        //cout<<seq[i]<<" "<<lm<<"\n";
        if(min({l1,l2,lm}) < (st.query(seq[i-1], seq[i-1]) + (seq[i] != seq[i-1]))){
            const int x = min({l1,l2,lm}) - st.query(seq[i-1], seq[i-1]) - (seq[i] != seq[i-1]);
            assert(x < 0);
            //cout<<st.query(seq[i-1], seq[i-1]) + x<<"\n";
            st.updaterange(seq[i-1],seq[i-1],x);
            //cout<<st.query(seq[i-1], seq[i-1])<<"\n\n";
        }
        st.updaterange(0,n,(seq[i] != seq[i-1]));   
        //for(int i=0;i<=2;i++) cout<<st.query(i, i)<<" ";
        //cout<<"\n";
    }
    int ans2 = st.query(0,n);
    cout<<min(ans1, ans2)<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}