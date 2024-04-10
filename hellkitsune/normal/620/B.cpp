#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int a, b;

int main() {
    scanf("%d%d", &a, &b);
    LL ans = 0;
    for (int i = a; i <= b; ++i) {
        for (int x = i; x > 0; x /= 10) {
            ans += arr[x % 10];
        }
    }
    cout << ans << endl;
    return 0;
}