#include <bits/stdc++.h>
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
    T base) : n(n), join(join), assign(assign), lazyassign(lazyassign), base(base){
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
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> p(n);
    cin>>p;
    vector<array<int, 2>> ct(n);
    {
        stack<int> prev;
        for(int i=0;i<n;i++){
            while(prev.size() > 0 && p[prev.top()] < p[i]) prev.pop();
            ct[i][0] = (prev.size() > 0 ? prev.top() : -1);
            prev.push(i);
        }
        while(prev.size() > 0) prev.pop();
        for(int i=n-1;i>=0;--i){
            while(prev.size() > 0 && p[prev.top()] < p[i]) prev.pop();
            ct[i][1] = (prev.size() > 0 ? prev.top() : n);
            prev.push(i);
        }
    }
    vector<int> ip(n+1);
    for(int i=0;i<n;i++) ip[p[i]] = i;
    vector<vector<int>> ct_best(n);
    vector<bool> is_left(n);
    for(int i=0;i<n;i++){
        is_left[i] = (i - ct[i][0] < ct[i][1] - i);
    }
    for(int i=0;i<n;i++){
        if(is_left[i]){
            ct_best[i].resize(i - ct[i][0], ct[i][1]);
        }
        else{
            ct_best[i].resize(ct[i][1] - i, ct[i][0]);
        }
    }
    for(int i=1;i<=n;i++){
        for(ll j=i+1;j*i<=n;j++){
            int mn = min({ip[i], ip[j], ip[i*j]});
            int mx = max({ip[i], ip[j], ip[i*j]});
            if(mn < ct[ip[i * j]][0] || mx > ct[ip[i * j]][1]) continue;
            if(is_left[ip[i * j]]){
                ct_best[ip[i * j]][ip[i * j] - mn] = min(mx, ct_best[ip[i * j]][ip[i * j] - mn]);
            }
            else{
                ct_best[ip[i * j]][mx - ip[i * j]] = max(mn, ct_best[ip[i * j]][mx - ip[i * j]]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(is_left[i]){
            for(int j=1;j<ct_best[i].size();j++){
                ct_best[i][j] = min(ct_best[i][j], ct_best[i][j-1]);
            }
        }
        else{
            for(int j=1;j<ct_best[i].size();j++){
                ct_best[i][j] = max(ct_best[i][j], ct_best[i][j-1]);
            }
        }
    }
    lazy_segment_tree<array<ll, 2>, array<ll, 2>> lst(n, [&](array<ll, 2> l, array<ll, 2> r){
        return array<ll, 2>({l[0] + r[0], l[1] + r[1]});
    }, [&](int k, array<ll, 2> u, array<ll, 2> v){
        return array<ll, 2>({(1<<k) * u[0] + v[0], (1<<k) * u[1] + v[1]});
    }, [&](array<ll, 2> u, array<ll, 2> v){
        return array<ll, 2>({u[0] + v[0], u[1] + v[1]});
    }, array<ll, 2>({0, 0}));
    vector<ll> ans(q);
    vector<array<int, 3>> left_sweep(q), right_sweep(q);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        --l;--r;
        left_sweep[i] = {l, r, i};
        right_sweep[i] = left_sweep[i];
        swap(right_sweep[i][0], right_sweep[i][1]);
    }
    sort(right_sweep.begin(), right_sweep.end());
    sort(left_sweep.begin(), left_sweep.end(), greater<array<int, 3>>());
    vector<vector<int>> iterate_over_left(n), iterate_over_right(n);
    //cout+is_left;
    //cout*ct_best;
    for(int i=0;i<n;i++){
        if(is_left[i]){
            for(int j=max(ct[i][0], 0);j<=i;j++){
                iterate_over_left[j].push_back(i);
            }
        }
        else{
            for(int j=i;j<=min(ct[i][1], n-1);j++){
                iterate_over_right[j].push_back(i);
            }
        }
    }
    for(int i=0,j=0;i<n;i++){
        for(auto &j : iterate_over_right[i]){
            if(i == j){
                if(ct_best[j][0] > ct[j][0]) lst.updaterange(ct[j][0] + 1, ct_best[j][0], array<ll, 2>({1, -i+1}));
                continue;
            }
            if(i == ct[j][1]){
                if(ct_best[j].back() > ct[j][0]) lst.updaterange(ct[j][0] + 1, ct_best[j].back(), array<ll, 2>({-1, i-1}));
                continue;
            }
            if(ct_best[j][i-j] > ct_best[j][i-j-1]) lst.updaterange(ct_best[j][i-j-1] + 1, ct_best[j][i-j], array<ll, 2>({1, -i+1}));
        }
        while(j < q && right_sweep[j][0] == i){
            auto qry = lst.query(right_sweep[j][1], right_sweep[j][0]);
            ans[right_sweep[j][2]] += qry[0] * i + qry[1];
            ++j;
        }
    }
    lst = lazy_segment_tree<array<ll, 2>, array<ll, 2>>(n, [&](array<ll, 2> l, array<ll, 2> r){
        return array<ll, 2>({l[0] + r[0], l[1] + r[1]});
    }, [&](int k, array<ll, 2> u, array<ll, 2> v){
        return array<ll, 2>({(1<<k) * u[0] + v[0], (1<<k) * u[1] + v[1]});
    }, [&](array<ll, 2> u, array<ll, 2> v){
        return array<ll, 2>({u[0] + v[0], u[1] + v[1]});
    }, array<ll, 2>({0, 0}));
    for(int i=n-1,j=0;i>=0;--i){
        for(auto &j : iterate_over_left[i]){
            if(i == j){
                if(ct_best[j][0] < ct[j][1]) lst.updaterange(ct_best[j][0], ct[j][1] - 1, array<ll, 2>({-1, i+1}));
                continue;
            }
            if(i == ct[j][0]){
                if(ct_best[j].back() < ct[j][1]) lst.updaterange(ct_best[j].back(), ct[j][1] - 1, array<ll, 2>({1, -i-1}));
                continue;
            }
            if(ct_best[j][j-i] < ct_best[j][j-i-1]) lst.updaterange(ct_best[j][j-i], ct_best[j][j-i-1] - 1, array<ll, 2>({-1, i+1}));
        }
        while(j < q && left_sweep[j][0] == i){
            auto qry = lst.query(left_sweep[j][0], left_sweep[j][1]); 
            ans[left_sweep[j][2]] += qry[0] * i + qry[1];
            ++j;
        }
    }
    for(auto &x : ans) cout<<x<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}