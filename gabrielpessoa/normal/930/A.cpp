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

const int SIZE  = 1E5+5;
const int MOD = 1E9+7;
const int DELTA = 1E5+2;
const double PI = atan(1)*4;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;
const double INFF = 1e100;

vi g[SIZE];
int d[SIZE];
bool podeSer[SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout << fixed << setprecision(8);
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int a = q.front();
        q.pop();
        for(int v : g[a]) {
            d[v] = d[a]+1;
            q.push(v);
        }
    }
    for(int i = 1; i <= n; i++) {
        podeSer[d[i]] = !podeSer[d[i]];
        //printf("d[%d] = %d\n", i, d[i]);
    }
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        ans += podeSer[i];
    }
    cout << ans << '\n';
 	return 0;
}