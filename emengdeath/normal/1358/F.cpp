#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int n;
long long a[N], b[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", &b[i]);
    vector<char> ans;
    if (n == 1&& a[1] != b[1]) {
        puts("IMPOSSIBLE");
        return 0;
    } else
    if (n ==  1&& a[1] == b[1]){
        puts("SMALL");
        puts("0");
        return 0;
    }
    if (n == 2) {
        long long a0 = a[1], a1 = a[2], b0 = b[1], b1 = b[2];
        long long cnt = 0;
        if (a0 > a1)
            swap(a0, a1);
        while (1) {
            if (b0 == a0 && b1 == a1) {
                break;
            }
            if (b0 <= b1) {
                if (b0 < a0 || b1 < a1) {
                    puts("IMPOSSIBLE");
                    return 0;
                }
                if (b0 == a0) {
                    long long v = max(1ll, (b1 - a1) / b0);
                    cnt += v;
                    b1 -= v * b0;
                } else {
                    long long v = b1 / b0;
                    cnt += v;
                    b1 -= v * b0;
                }
            } else {
                swap(b0, b1);
            }
        }
        if (cnt > 200000) {
            puts("BIG");
            printf("%lld\n", cnt);
            return 0;
        }
    }
    int cnt = 0;
    while (1) {
        bool sig = 1, sig1 = 1;
        bool the_same = (a[1] == b[1]), re_same = (a[1] == b[n]);
        for (int i = 2; i <= n; i ++)
            sig &= (b[i - 1] < b[i]), sig1 &= (b[i - 1] > b[i]), the_same &= (b[i] == a[i]), re_same &= (a[i] == b[n - i + 1]);
        if (the_same) break;
        if (re_same) {
            ans.push_back('R');
            break;
        }
        if (!sig && !sig1) {
            puts("IMPOSSIBLE");
            return 0;
        }
        if (sig) {
            if (max(a[1], a[n]) > max(b[1], b[n]) || min(a[n], a[1]) > min(b[n], b[1])) {
                puts("IMPOSSIBLE");
                return 0;
            }
            for (int i = n; i >= 2; i --)
                b[i] -= b[i - 1];
            ans.push_back('P');
            cnt ++;
        } else {
            reverse(b + 1, b + n + 1);
            ans.push_back('R');
        }
    }
    if (cnt > 200000) {
        puts("BIG");
        printf("%d\n", cnt);
    } else {
        puts("SMALL");
        printf("%d\n", (int)ans.size());
        reverse(ans.begin(), ans.end());
        for (auto u:ans)
            printf("%c", u);
    }
    return 0;
}