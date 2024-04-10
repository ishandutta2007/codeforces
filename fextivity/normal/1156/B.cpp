#include<bits/stdc++.h>
using namespace std;

// Shortcut

#define int long long
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)

// I/O & Debug

#define PrintV(a) for (int iiii = 0; iiii < a.size(); iiii++) cout << a[iiii] << ' ';
#define PrintVl(a) for (int iiii = 0; iiii < a.size(); iiii++) cout << a[iiii] << endl;
#define PrintA(a, n) for (int iiii = 0; iiii < n; iiii++) cout << a[iiii] << ' ';
#define PrintAl(a, n) for (int iiii = 0; iiii < n; iiii++) cout << a[iiii] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
/*
#define debug(args...){ string _sDEB = #args; replace(_sDEB.begin(), _sDEB.end(), ',', ' '); stringstream _ssDEB(_sDEB); istream_iterator<string> _itDEB(_ssDEB); DEB(_itDEB, args); }
void DEB(istream_iterator<string> it) {}
template<typename T, typename... Args>
void DEB(istream_iterator<string> it, T a, Args... args){
    cout << *it << " = " << a << endl;
    DEB(++it, args...);
}
*/

// Functions

//#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a));
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ld> vld;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int n = s.length();
        vi a, b;
        a.clear();
        b.clear();
        bool ck = 1;
        For(i, 1, n){
            if (abs(s[i] - s[i - 1]) == 1){
                ck = 0;
                break;
            }
        }
        if (ck){
            cout << s << endl;
            continue;
        }
        sort(bend(s));
        int x = -1, y = -1;
        For(i, 1, n){
            For(j, 0, i){
                if (abs(s[i] - s[j]) != 1 && abs(s[i] - s[j]) % 2 == 1){
                    x = i;
                    y = j;
                    if ((s[x] - 'a') % 2 == 0) swap(x, y);
                    break;
                }
            }
        }
        if (x == -1){
            cout << "No answer" << endl;
            continue;
        }
        string t = "";
        For(i, 0, n){
            if ((s[i] - 'a') % 2 == 1 && i != x && i != y) t += s[i];
        }
        t += s[x];
        t += s[y];
        For(i, 0, n){
            if ((s[i] - 'a') % 2 == 0 && i != x && i != y) t += s[i];
        }
        //cout << t << endl;
        ck = 1;
        For(i, 1, n){
            if (abs(t[i] - t[i - 1]) == 1){
                ck = 0;
                break;
            }
        }
        if (ck){
            cout << t << endl;
            continue;
        }
        cout << "No answer" << endl;
    }
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