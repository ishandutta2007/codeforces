#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define ld long double
#define endl '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define Rep(indx, a, b) for (i = (a) - ((a) > (b)); i != (b) - ((a) > (b)); i += 1 - 2 * ((a) > (b)))
#define For(indx, a, b) for (int indx = a; indx < b; indx++)
#define ForE(indx, a, b) for (int indx = a; indx <= b; indx++)
#define Ford(indx, a, b) for (int indx = a; indx > b; indx--)
#define FordE(indx, a, b) for (int indx = a; indx >= b; indx--)
#define Fora(indx, a) for (auto indx : a)

#define PrintV(x) for (int indx = 0; indx < x.size(); indx++) cout << x[indx] << ' ';
#define PrintVl(x) for (int indx = 0; indx < x.size(); indx++) cout << x[indx] << endl;
#define PrintA(x, n) for (int indx = 0; indx < n; indx++) cout << x[indx] << ' ';
#define PrintAl(x, n) for (int indx = 0; indx < n; indx++) cout << x[indx] << endl;
#define Ptest(x) return cout << x, 0;
#define Pmtest(x) cout << x << endl; continue;
#define isvowel(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y')
#define gl(x) getline(cin, x)
#define mset(x) memset(x, 0, sizeof(x));

#define pque priority_queue
#define mts multiset
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 5e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, t, u;
int a[N], b[N], c;
bool ck;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    string s;
    For(i, 0, n){
        cin >> s;
        t = 0;
        u = 0;
        ck = 1;
        For(j, 0, s.length()){
            t += ((s[j] == '(') ? 1 : (-1));
            if (t < 0) ck = 0, u = min(u, t);
        }
        if (u == 0){
            if (t > 0) a[t]++;
            else if (t < 0) b[abs(t)]++;
            else c++;
        }
        if (u == t) b[abs(u)]++;
    }
    int ans = 0;
    For(i, 0, 500002){
        ans += min(a[i], b[i]);
    }
    ans += c / 2;
    cout << ans;
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/