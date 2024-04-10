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
        H = 32 - __builtin_clz(n-1);
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
    int findl(T x){
        int idx = 1;
        T curr = base;
        int h = H;
        while(idx < n){
            --h;
            if(!isempty[idx]){
                apply((idx<<1), lazytree[idx], h);
                apply((idx<<1)|1, lazytree[idx], h);
                isempty[idx]=1;
            }
            idx <<= 1;
            if(join(curr, segtree[idx]) <= x){
                curr = join(curr, segtree[idx]);
                ++idx;
            }
        }
        if(join(curr, segtree[idx]) <= x){
            return idx+1-n;
        }
        else{
            return idx-n;
        }
    }
    int findr(T x){
        int idx = 1;
        T curr = base;
        int h = H;
        while(idx < n){
            --h;
            if(!isempty[idx]){
                apply((idx<<1), lazytree[idx], h);
                apply((idx<<1)|1, lazytree[idx], h);
                isempty[idx]=1;
            }
            idx <<= 1;
            if(join(curr, segtree[idx]) > x){
                curr = join(curr, segtree[idx]);
                ++idx;
            }
        }
        if(join(curr, segtree[idx]) > x){
            return idx+1-n;
        }
        else{
            return idx-n;
        }
    }
    void updaterange(int l, int r, U value){
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
const int INF = 1e9;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<ll> seq(n);
    cin>>seq;
    int p2 = 1; while(p2 < n) p2<<=1;
    seq.resize(p2, INF);
    lazy_segment_tree<ll,ll> st1(seq, [&](ll x,ll y){
        return x+y;
    },
    [&](int h,ll x,ll y){
        return x * (1<<h);
    },
    [&](ll x,ll y){
        return x;
    }, 0);
    lazy_segment_tree<ll,ll> st2(seq, [&](ll x,ll y){
        return min(x,y);
    }, 
    [&](int h, ll x, ll y){
        return x;
    }, 
    [&](ll x, ll y){
        return x;
    }, INF);
    for(int i=0;i<q;i++){
        int t,x,y;
        cin>>t>>x>>y;
        --x;
        if(t == 1){
            int l = st2.findr(y);
            if(l <= x){
                st2.updaterange(l,x,y);
                st1.updaterange(l,x,y);
            }
        }
        if(t == 2){
            int ans = 0;
            int cnt = 0;
            while(x < n && y && cnt < 40){
                int l = max(x, st2.findr(y));
                int r;
                if(l >= n) break;
                if(l == 0){
                    r = st1.findl(y);
                }
                else{
                    r = st1.findl(y + st1.query(0,l-1));
                }
                y -= st1.query(l,r-1);
                ans += r - l;
                x = r;
                ++cnt;
            }
            cout<<ans<<"\n";
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}