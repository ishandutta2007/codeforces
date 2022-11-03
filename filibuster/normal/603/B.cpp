#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1e6 + 13;

/*
*/

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    if(k & 1)
        return pw * 1ll * pw % M * n % M;
    else
        return pw * 1ll * pw % M;
}

int used[N];
int k, p;

bool dfs(int v) {
    used[v] = 1;

    int u = v * 1ll * k % p;
    if(used[u] == 1) {
        used[v] = 2;
        return true;
    } else if(used[u] == 2) {
        used[v] = 2;
        return false;
    }

    bool res = dfs(u);
    used[v] = 2;
    return res;
}

int main() {
    cin >> p >> k;

    if(k == 0) {
        cout << pow2(p, p - 1) << endl;
        return 0;
    }

    if(k == 1) {
        cout << pow2(p, p) << endl;
        return 0;
    }

    int cnt = 0;
    for(int i = 1; i < p; i++) {
        if(!used[i]) {
            cnt += dfs(i);
//            cnt++;
        }
    }

    cout << pow2(p, cnt);
}