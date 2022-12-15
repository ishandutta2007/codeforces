#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

const int ms = 2e5+5;
const ll mod = 1e9+7;

set<int> g[ms];
int n;
queue<int> q;
int vis[ms];
int a[ms];

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] != b[i] && a[i+1] != b[i+1] && a[i] != a[i+1]) {
            ans++;
            swap(a[i], a[i+1]);
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) ans++;
    }
    cout << ans << '\n';
}