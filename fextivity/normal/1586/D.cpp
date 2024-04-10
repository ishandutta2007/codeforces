#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e2 + 5;

int n;
int p[N];

int a[N];

int ask(){
    cout << "? ";
    ForE(i, 1, n){
        cout << a[i] << ' ';
    } cout << endl;
    int ans; cin >> ans;
    return ans;
}

void answer(){
    cout << "! ";
    ForE(i, 1, n){
        cout << p[i] << ' ';
    } cout << endl;
    exit(0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    For(i, 1, n){
        a[i] = 1;
    }
    p[n] = 1;
    ForE(i, 2, n){
        a[n] = i;
        if (ask() == 0){
            p[n] = n + 2 - i;
            break;
        }
    }
    ForE(x, 1, n){
        if (x == p[n]){
            continue;
        }
        int y = min(0, p[n] - x) - 1;
        For(i, 1, n){
            a[i] = p[n] - x - y;
        }
        a[n] = -y;
        p[ask()] = x;
    }
    answer();
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/