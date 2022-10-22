
#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int main() {
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, x;
        int a = 0, b = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x >= a) {
                b = a;
                a = x;
            } else if (x > b) b = x;
        }

        cout << a + b << endl;
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}