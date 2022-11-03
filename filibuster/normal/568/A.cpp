#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e6 + 13;

bool isp[N];

bool ispal(int x) {
    vector<int> a;
    while(x > 0) {
        a.push_back(x % 10);
        x /= 10;
    }

    for(int i = 0; i < a.size() / 2; i++)
        if(a[i] != a[a.size() - i - 1])
            return false;

    return true;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int p1, q1;
    cin >> p1 >> q1;

    int ans = 1;
    int cnt1 = 0, cnt2 = 1;
    for(int i = 2; i < N; i++) {
        if(!isp[i]) {
            cnt1++;
            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    isp[j] = true;
        }

        if(ispal(i)) {
            cnt2++;
        }

        if(p1 * cnt2 >= q1 * cnt1)
            ans = i;
    }

    cout << ans;
}