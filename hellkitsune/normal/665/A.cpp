#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a, ta, b, tb, hh, mm;
const int MX = 60 * 23 + 59;

int main() {
    scanf("%d%d%d%d%d:%d", &a, &ta, &b, &tb, &hh, &mm);
    int startTime = hh * 60 + mm - tb + 1;
    int endTime = hh * 60 + mm + ta - 1;
    int ans = 0;
    for (int t = 5 * 60; t <= MX; t += b) {
        if (t >= startTime && t <= endTime) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}