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
vector<int> c;
int table[20][int(3e5+7)];
ll bl[20][int(3e5 + 7)];
template<typename T, int lgn>
struct sparse_table{
    int n;
    sparse_table(vector<T> seq) :  n(seq.size()){
        build(seq);
    }
    void build(vector<T> seq){
        for(int i=0;i<n;i++){
            table[0][i] = seq[i];
        }
        for(int i=0;i+1<lgn;i++){
            for(int j=0;j<n;j++){
                if(j + (1<<i) < n){
                    table[i+1][j] = c[table[i][j]] > c[table[i][j+(1<<i)]] ? table[i][j+(1<<i)] : table[i][j];
                }
                else{
                    break;
                }
            }
        }
    }
    int query(int l,int r){
        ++r;
        int lg = 31 - __builtin_clz(r - l);
        return c[table[lg][l]] > c[table[lg][r-(1<<lg)]] ? table[lg][r-(1<<lg)] : table[lg][l]; 
        //assert(l <= ans && ans < r)
    }
};
const int INF = 1e9 + 7;
const int LGN = 20;
void solve(){
    int n,q,k;
    cin>>n>>q>>k;
    c.resize(n);
    cin>>c;
    vector<int> _(n);
    iota(_.begin(), _.end(), 0);
    sparse_table<int, 20> st(_);
    for(int i=0;i<n;i++){
        bl[0][i] = c[st.query(i, min(i + k - 1, n - 1))];
    }
    stack<int> stk;
    stk.push(0);
    vector<int> nxt(n, n);
    for(int i=1;i<n;i++){
        while(stk.size() > 0 && c[stk.top()] > c[i]){
            nxt[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    for(int lg=1;lg<LGN;lg++){
        for(int i=0;i<n;i++){
            bl[lg][i] = 0;
            int u = st.query(i, min(n - 1, i + k - 1));
            int done = min((1<<lg), (nxt[u] - i) / k);
            if(nxt[u] == n) done = (1<<lg);
            bl[lg][i] += 1ll * done * c[u];
            int lf = (1<<lg) - done;
            for(int j=lg-1;j>=0;--j){
                int sblk = min(ll(n - 1), i + ll(done) * k);
                if(lf >= (1<<j)){
                    bl[lg][i] += bl[j][sblk];
                    done += (1<<j);
                    sblk = min(ll(n - 1), i + ll(done) * k);
                    int nmn = st.query(i, sblk - 1);
                    int odone = done;
                    if(nxt[nmn] != n) done += (nxt[nmn] - sblk) / k;
                    else done = (1<<lg);
                    done = min(done, (1<<lg));
                    bl[lg][i] += 1ll * (done - odone) * c[nmn];
                    lf = (1<<lg) - done;
                }
            }
        }
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        --l;--r;
        ll ans = c[l];
        int len = (r - l) / k;
        if(len == 0){
            cout<<ans<<"\n";
            continue;
        }
        int done = min(len, (nxt[l] - l - 1) / k);
        if(nxt[l] == n) done = len;
        ans += 1ll * done * c[l];
        l++;
        int lf = len - done;
        for(int j=LGN-1;j>=0;--j){
            int sblk = min(ll(n - 1), l + ll(done) * k);
            if(lf >= (1<<j)){
                ans += bl[j][sblk];
                done += (1<<j);
                sblk = min(ll(n - 1), l + ll(done) * k);
                int nmn = st.query(l, sblk - 1);
                int odone = done;
                if(nxt[nmn] != n) done += (nxt[nmn] - sblk) / k;
                else done = len;
                done = min(done, len);
                ans += 1ll * (done - odone) * c[nmn];
                lf = len - done;
            }
        }
        cout<<ans<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}