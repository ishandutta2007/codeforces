#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define umap unordered_map
#define flush fflush(stdout)
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ln "\n"
#define all(v) v.begin(),v.end()
#define MAX 1000000009
#define MOD 1000000007
#define mid (start + end) / 2
#define R(ii) (ii + ii + 1)
#define L(ii) (ii + ii)
#define N 100005
using namespace std;
typedef pair<ll,ll> pp;
typedef vector<ll> vi;
ll n, q,  t, x, a, b, c, y;
string s;
map <string, ll> m;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    vector <ll> ap;
    set <string> S;
    while (n--){
        cin >> s;
        S.insert(s);
        m[s]++;
    }
    ll tp = 0, ans = 0;
    string r = "";
    for(auto a : S){
        string tmp = a;
        reverse(all(tmp));
        ll ts =  min(m[tmp], m[a]);
        if (tmp == a){
            ts /= 2;
        }
        //cout << a << " " << ts << ln;
        for(int i = 0; i < ts; i++){
            r += a;
        }
        ans += min(m[tmp], m[a]);
        m[tmp] -= ts;
        m[a] -= ts;
    }
    string old = r;
    for(auto a : S){
        //cout << a << " " << m[a] << ln;
        if(m[a] > 0){
            bool asd = 1;
            for(int i = 0; i < s.size(); i++){
                if (a[i] != a[s.size() - i - 1]){
                    asd = 0;
                }
            }
            if (asd){
                ans++;
                r += a;
                break;
            }
        }
    }
    reverse(all(old));
    r += old;
    cout << r.size() << "\n" << r;
    return 0;
}