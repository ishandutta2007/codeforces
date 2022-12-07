#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL a, b;
string ans;

int main() {
    cin >> a >> b;
    while (a > 1 || b > 1) {
        if (a > b) {
            LL x = a / b;
            if (b == 1) --x;
            a -= b * x;
            if (a == 0) {
                printf("Impossible\n");
                return 0;
            }
            ostringstream oss;
            oss << x << 'A';
            ans += oss.str();
        } else {
            LL x = b / a;
            if (a == 1) --x;
            b -= a * x;
            if (b == 0) {
                printf("Impossible\n");
                return 0;
            }
            ostringstream oss;
            oss << x << 'B';
            ans += oss.str();
        }
    }
    printf("%s\n", ans.c_str());
    return 0;
}