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
struct segment_tree {
    int n;
    vector<T> segtree;
    function<T(const T&,const T&)> join;
    T base = T();
    segment_tree(int n, function<T(const T&,const T&)> join, T base = T()) : n(n), join(join), base(base){
        segtree.resize(n << 1, base);
    }
    void build() {
        for (int i = n - 1; i > 0; --i) {
            segtree[i] = join(segtree[(i << 1)], segtree[(i << 1) | 1]);
        }
    }
    segment_tree(vector<T> seq, function<T(const T&,const T&)> join, T base = T()) : n(seq.size()), join(join), base(base){
        segtree.resize(n << 1, base);
        for (int i = 0; i < n; i++) {
            segtree[n + i] = seq[i];
        }
        build();
    }
    void calc(int pos){
        pos >>= 1;
        while (pos) {
            segtree[pos] = join(segtree[pos << 1], segtree[(pos << 1) | 1]);
            pos >>= 1;
        }
    }
    void set(int pos, T val){
        pos+=n;
        segtree[pos] = val;
        calc(pos);
    }
    void increment(int pos, T val){
        pos+=n;
        segtree[pos] = join(segtree[pos], val);
        calc(pos);
    }
    T query(int l, int r) {
        T ansl = base;
        T ansr = base;
        l += n;
        r += n + 1;
        while (l < r) {
            if (l & 1) {
                ansl = join(ansl, segtree[l++]);
            }
            if (r & 1) {
                ansr = join(segtree[--r], ansr);
            }
            l >>= 1;
            r >>= 1;
        }
        return join(ansl, ansr);
    }
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    cin>>a;
    sort(a.begin(), a.end(), greater<int>());
    while(n > m){
        a.pop_back();
        --n;
    }
    sort(a.begin(), a.end());
    vector<vector<int>> stud(m);
    int tots = 0;
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        tots += k;
        stud[i].assign(k, 0);
        cin>>stud[i];
    }
    segment_tree<int> st(n+1, [&](int x,int y){
        return max(x, y);
    }, -1e9);
    vector<int> ini(n+1);
    vector<int> rch(m);
    for(int i=0;i<m;i++){
        ll sum = accumulate(stud[i].begin(), stud[i].end(), 0ll);
        ll k = stud[i].size();
        int mn = 0;
        int mx = m;
        while(mn < mx){
            int mid = mn + mx;
            mid >>= 1;
            if(mid < m && sum > k * a[mid]){
                mn = mid + 1;
            }
            else{
                mx = mid;
            }
        }
        ini[mn]++;
        rch[i] = mn;
    }
    //cout+ini;
    for(int i=n,c=0;i>=0;--i){
        c += ini[i];
        st.set(i, -n + i + c);
    }
    //for(int i=0;i<=n;i++) cout<<st.query(i, i)<<" ";
    //cout<<"\n\n";
    string ans;
    for(int i=0;i<m;i++){
        ll sum = accumulate(stud[i].begin(), stud[i].end(), 0ll);
        for(int j=0;j<stud[i].size();j++){
            int mn = 0, mx = m;
            sum -= stud[i][j];
            ll k = stud[i].size() - 1;
            while(mn < mx){
                int mid = mn + mx;
                mid >>= 1;
                if(mid < m && sum > k * a[mid]){
                    mn = mid + 1;
                }
                else{
                    mx = mid;
                }
            }
            sum += stud[i][j];
            //cout<<rch[i]<<" "<<mn<<"\n";
            if(rch[i] == mn){
                if(st.query(0, n) <= 0){
                    ans.push_back('1');
                }
                else{
                    ans.push_back('0');
                }
            }
            if(rch[i] < mn){
                if(max({st.query(0, rch[i]), st.query(rch[i] + 1, mn) + 1, st.query(mn + 1, n)}) <= 0){
                    ans.push_back('1');
                }
                else{
                    ans.push_back('0');
                }
            }
            if(rch[i] > mn){
                if(max({st.query(0, mn), st.query(mn+1, rch[i]) - 1, st.query(rch[i]+1, n)}) <= 0){
                    ans.push_back('1');
                }
                else{
                    ans.push_back('0');
                }
            }
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}