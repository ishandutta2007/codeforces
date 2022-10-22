#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <ii > vii;

const int mod = 1e9 + 7, inf = 1e18 + 5, N = 1e5 + 5;

signed main(){
    int n, m;
    cin >> n >> m;
    if (m >= 2 * n){
        cout << 0;
        return 0;
    }
    if (m <= n + 1){
        cout << (m - 1) / 2;
        return 0;
    }
    int p = m - n;
    cout << (n - p + 1) / 2;
}