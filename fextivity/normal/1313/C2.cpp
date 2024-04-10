#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

#define int long long
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

#define PrintV(a) Fora(iiii, a) cout << iiii << ' '; cout << endl;
#define PrintVl(a) Fora(iiii, a) cout << iiii << endl;
#define PrintA(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << ' '; cout << endl;
#define PrintAl(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << endl;
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
#define mset(a) memset(a, 0, sizeof(a))
#define mset1(a) memset(a, 1, sizeof(a))
#define msetn1(a) memset(a, -1, sizeof(a))
#define msetinf(a) memset(a, 0x3f, sizeof(a))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
#define y0 _y0_
#define y1 _y1_
#define div divi
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

const int N = 5e5 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

ll sum;
int n, ans;
int a[N], aa[N], b[N], c[N], vans[N];
ll d[N], e[N];
int pos[N];
set <int> stt; map <int, int> mpp;

struct lazy_segment_tree{
    int seg[4 * N], lazy[4 * N], marked[4 * N];
    
    void down(int id, int l, int r){
        if (marked[id]){
            lazy[id << 1] = lazy[id];
            lazy[id << 1 | 1] = lazy[id];
            seg[id << 1] = lazy[id];
            seg[id << 1 | 1] = lazy[id];
            marked[id] = 0;
            marked[id << 1] = 1;
            marked[id << 1 | 1] = 1;
        }
    }
    
    void update(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            seg[id] = val;
            lazy[id] = val;
            marked[id] = 1;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
    }
    
    int get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return -inf;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
} it;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
        stt.insert(a[i]);
    }
    int idx = 1;
    Fora(v, stt){
        mpp[v] = idx;
        idx++;
    }
    idx--;
    ForE(i, 1, n){
        aa[i] = mpp[a[i]];
    }
    ForE(i, 1, n){
        if (aa[i] == 1){
            b[i] = 0;
        }
        else{
            b[i] = it.get(1, 1, idx, 1, aa[i] - 1);
        }
        it.update(1, 1, idx, aa[i], idx, i);
    }
    it.update(1, 1, idx, 1, idx, 0);
    ForE(i, 1, n){
        if (aa[n - i + 1] == 1){
            c[n - i + 1] = n + 1;
        }
        else{
            c[n - i + 1] = n + 1 - it.get(1, 1, idx, 1, aa[n - i + 1] - 1);
        }
        it.update(1, 1, idx, aa[n - i + 1], idx, i);
    }
    ForE(i, 1, n){
        d[i] = (ll)(i - b[i]) * a[i] + d[b[i]];
    }
    FordE(i, n, 1){
        e[i] = (ll)(c[i] - i) * a[i] + e[c[i]];
    }
    ForE(i, 1, n){
        ll tmp = d[i] + e[i] - a[i];
        if (tmp > ans){
            ans = tmp;
            idx = i;
        }
    }
    int val;
    vans[idx] = a[idx];
    val = a[idx];
    FordE(i, idx - 1, 1){
        val = min(val, a[i]);
        vans[i] = val;
    }
    val = a[idx];
    ForE(i, idx + 1, n){
        val = min(val, a[i]);
        vans[i] = val;
    }
    PrintA(vans, 1, n);
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