#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define umap unordered_map
#define flush fflush(stdout)
#define For(ii,aa,bb) for(int ii = aa; ii < bb; ii++) 
#define st first
#define nd second 
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ln "\n"
#define all(v) v.begin(),v.end()
#define MAX 1000000009
#define MOD 998244353
#define mid (start + end) / 2 
#define R(ii) (ii + ii + 1)
#define L(ii) (ii + ii)
#define N 500005
using namespace std;
typedef pair<ll,ll> pp;
typedef pair<pp,pp> pp4; 
typedef vector<ll> vi; 
ll n, t, x, a, b, k , c ,y, p, c1, c2, val;
string s;   
bool cmp(pp val1, pp val2){
    return ((double) val1.st / val1.nd) > ((double) val2.st / val2.nd);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("outt.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--){
        map <char, ll> m; 
        cin >> c2 >> c1 >> val >> s;
        reverse(all(s));
        m['B'] = c1;
        m['A'] = c2;
        s += 'q';
        ll last = 1;
        for(int i = 2; i < s.size(); i++){
            if(s[i] != s[i - 1]){
                if(val >= m[s[i - 1]]) val -= m[s[i - 1]];
                else break;
                //cout << i << " " << val << ln;
                last = i;
            }
        }
        cout << s.size() - last << ln;
    }

    
    return 0;
}