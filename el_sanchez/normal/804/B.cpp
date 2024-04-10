#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = (int)1e9;
const int MAXN = 1000500;
const int MOD = (int)1e9 + 7;

int n;
string s;
int Bs, ans;

int main() {

    while (cin >> s) {
        n = (int)s.size();
        Bs = 0;
        ans = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'b') {
                Bs = (Bs + 1) % MOD;
            } else {
                if (Bs > 0) {
                    ans = (ans + Bs) % MOD;
                    Bs = (Bs * 2) % MOD;
                }
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}