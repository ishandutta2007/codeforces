#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

#define all(x) x.begin(), x.end()
#define pb emplace_back
#define mp make_pair

using namespace std;

void setup() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
    ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif

    srand(time(NULL));
}

const int N = 100;

vector<int> g[N];

void dfs(int v, vector<int> &used) {
    used[v] = 1;
    for(auto u: g[v]) {
        if (!used[u])
            dfs(u, used);
    }
}

int pow (int a, int n) {
    int ans = 1;
    for(int i = 0; i < n; ++i) {
        ans *= a;
    }
    return ans;
}

signed main() {
    setup();

    string s;
    cin >> s;
    int n;
    if (s.size() == 1)
        n = (s[0] -  '0') % 4;
    else
        n = ((s[s.size() - 2] - '0') * 10 + (s[s.size() - 1] - '0')) % 4;
    //cout << n << '\n';
    cout << (pow(1, n) + pow(2, n) + pow(3, n) + pow(4, n)) % 5;
}