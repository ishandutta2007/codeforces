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
vector<int> primes;
vector<bool> prime;
void sieve(const int n){
    prime.resize(n+1, 1);
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            primes.pb(i);
            for(int j=2*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
}
hash<string> hashof;
mt19937 rng(hashof("ElephantOrz"));
const int QPERGUESS = 5;
const int GUESSES = 1000;
const int EXGUESSES = 5000;
static_assert(QPERGUESS * GUESSES <= EXGUESSES);
//#define debug
void solve(){
    int n;
    cin>>n;
    #ifdef debug
    n = 93;
    vector<int> a(93);
    //cin>>a;
    iota(a.begin(), a.end(), 18676);
    auto query = [&](int x,int y){
        //cout<<"? "<<x+1<<" "<<y+1<<"\n";
        //cout.flush();
        //int ans;
        //cin>>ans;
        assert(x != y);
        assert(x >= 0 && y >= 0);
        return lcm<ll>(a[x], a[y]);
    };
    #else
    auto query = [&](int x,int y){
        cout<<"? "<<x+1<<" "<<y+1<<"\n";
        cout.flush();
        ll ans;
        cin>>ans;
        return ans;
    };
    #endif
    int bestid = -1;
    int bestnum = -1;
    if(n < 70){
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ll g = 0;
            for(int j=0;j<n;j++){
                if(i == j) continue;
                if(g == 0) g = query(i, j);
                else g = gcd(g, query(j, i));
            }
            ans[i] = g;
        }
        if(n == 3 && *max_element(ans.begin(), ans.end()) - *min_element(ans.begin(), ans.end()) != 2) ans[max_element(ans.begin(), ans.end()) - ans.begin()] /= 2;
        cout<<"! ";
        cout+ans;
        cout.flush();
        return;
    }
    if(n < 100){
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ll g = 0;
            for(int j=0;j<n;j++){
                if(i == j) continue;
                if(rng() % 100 > 20) continue;
                if(g == 0) g = query(i, j);
                else g = gcd(g, query(j, i));
            }
            ans[i] = g;
        }
        if(n == 3 && *max_element(ans.begin(), ans.end()) - *min_element(ans.begin(), ans.end()) != 2) ans[max_element(ans.begin(), ans.end()) - ans.begin()] /= 2;
        cout<<"! ";
        cout+ans;
        cout.flush();
        return;
    }
    for(int _=0;_<GUESSES;_++){
        int u = rng() % n;
        ll g = 0;
        for(int _=0;_<QPERGUESS;_++){
            int v = rng() % (n - 1);
            if(v >= u) v++;
            if(g == 0) g = query(u, v);
            else g = gcd(g, query(u, v));
        }
        if(g < prime.size() && prime[g] && g > bestnum){
            bestid = u;
            bestnum = g;
        }
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        if(i != bestid) ans[i] = query(bestid, i) / bestnum;
        else ans[i] = bestnum;
    }
    cout<<"! ";
    cout+ans;
    cout.flush();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    sieve(3e5 + 7);
    while(t--){
        solve();
    }
}