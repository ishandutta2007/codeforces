#include<bits/stdc++.h>
using namespace std;

// Shortcut

#define int long long
#define ld long double
#define endl '\n'
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

#define PrintV(a) for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
#define PrintVl(a) for (int i = 0; i < a.size(); i++) cout << a[i] << endl;
#define PrintA(a, n) for (int i = 0; i < n; i++) cout << a[i] << ' ';
#define PrintAl(a, n) for (int i = 0; i < n; i++) cout << a[i] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
#define debug(args...){ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args){
	cout << *it << " = " << a << endl;
	err(++it, args...);
}

// Functions

#define bend(a) a.begin(),a.end()
#define mset(a) memset(a, 0, sizeof(a));
#define sortV(a) sort(bend(a));
#define sortA(a, n) sort(a, a + n);
#define rev(s) reverse(bend(a));

// Data Structure

#define pque priority_queue
#define mts multiset
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 5e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    string t = s;
    s = "";
    For(i, 0, t.length()){
        if (t[i] < 'a' || t[i] > 'z'){
            s.pb(t[i]);
        }
    }
    bool ck1 = 0, ck2 = 0, ck3 = 0, ck4 = 0;
    For(i, 0, s.length()){
        if (s[i] == ']' && ck3){
            ck4 = 1;
            break;
        }
        else if (s[i] == ':' && ck2) ck3 = 1;
        else if (s[i] == ':' && ck1) ck2 = 1;
        else if (s[i] == '[') ck1 = 1;
    }
    if (!(ck1 && ck2 && ck3 && ck4)) Ptest("-1");
    int l = 0, r = s.length() - 1;
    ck1 = 0;
    For(i, 0, s.length()){
        if (s[i] == ':' && ck1){
            l = i + 1;
            break;
        }
        else if (s[i] == '[') ck1 = 1;
    }
    ck1 = 0;
    FordE(i, s.length(), 0){
        if (s[i] == ':' && ck1){
            r = i - 1;
            break;
        }
        else if (s[i] == ']') ck1 = 1;
    }
    int ans = 4;
    ForE(i, l, r){
        if (s[i] == '|') ans++;
    }
    cout << ans;
}

/*
----------------------------------+
INPUT:                            |
==============================    |

==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |

==============================    |
----------------------------------+
*/