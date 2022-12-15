#include <bits/stdc++.h>
using namespace std;

typedef long double T;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;
typedef pair<T, T> dd;
typedef pair<dd, int> ddi;

const int SIZE  = 3E5+5;
const int MOD = 1E9+7;
const int DELTA = 1E5+2;
const double PI = atan(1)*4;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;
const double INFF = 1e100;

ii sl[SIZE];
int qnt[SIZE];
int lis[SIZE];
int rLis[SIZE];
int lisAux[SIZE];

int binarySearch(int l, int r, int v) {
    while(r > l + 1) {
        int m = l + (r-l)/2;
        if(lisAux[m] > v) r = m;
        else l = m;
    }
    return r;
}

void calculateLis(int n) {
    int len = 1;
    lisAux[0] = qnt[1];
    lis[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(qnt[i] < lisAux[0]) lisAux[0] = qnt[i];
        else if(qnt[i] >= lisAux[len-1]) lisAux[len++] = qnt[i];
        else lisAux[binarySearch(-1, len - 1, qnt[i])] = qnt[i];
        lis[i] = len;
    }
}

void calculaterLis(int n) {
    int len = 1;
    lisAux[0] = qnt[n];
    rLis[n] = 1;
    for(int i = n - 1; i >= 1; i--) {
        if(qnt[i] < lisAux[0]) lisAux[0] = qnt[i];
        else if(qnt[i] >= lisAux[len-1]) lisAux[len++] = qnt[i];
        else lisAux[binarySearch(-1, len - 1, qnt[i])] = qnt[i];
        rLis[i] = len;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout << fixed << setprecision(13);
    int n, m;
    cin >>n >>m;
    for(int i = 1; i <= m; i++) {
        sl[i-1] = ii(i, 0);
    }
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        sl[m+i+i] = ii(l, -1);
        sl[m+i+i+1] = ii(r, 1);
    }
    sort(sl, sl+m+n+n);
    int qntAgora = 0;
    for(int i = 0; i < m + n + n; i++) {
        if(sl[i].second == 0) qnt[sl[i].first] = qntAgora;
        else if(sl[i].second == -1) qntAgora++;
        else qntAgora--;
    }
    calculateLis(m);
    calculaterLis(m);
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        ans = max(ans, lis[i] + rLis[i] - 1);
    }
    cout << ans << '\n';
 	return 0;
}