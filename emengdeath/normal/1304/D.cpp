#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
int n;
bool a[N];
int ans[N], ans1[N];
void output(int*ans) {
    for (int i  = 0; i < n; i ++)
        printf("%d%c", ans[i], " \n"[i == n - 1]);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i= 1; i < n; i ++){
           char c;
           scanf(" %c", &c);
           a[i] = (c == '<');
           ans[i] = 0;
        }
        ans[0] = 0;
        int r = n;
        for (int i = n - 1; i >= 0; i --) {
            if (i == n-1) {
                if (a[i])
                    ans[i] = (r --);
            }else
                if (i == 0) {
                } else {
                    if (a[i])
                        ans[i] = (r --);
                }
        }
        for (int i = 0; i < n ;i ++) {
            if (!ans[i])
                ans[i] = (r--);
        }
        int sum = 0;
        for (int i = n - 1; i >= 0; i --) {
            ans1[i] = 0;
            if (i == n-1) {
            }else
            if (i == 0) {
                if (a[i + 1])
                    ans1[i] = 1, ++sum;
            } else {
                if (a[i + 1])
                    ans1[i] = 1, ++sum;
            }
        }
        int rr = n;
        for (int i = 0; i < n ;) {
            if (!ans1[i]) {
                ans1[i ++] = rr --;
                continue;
            }
            int r = i;
            while (r+ 1< n && ans1[r + 1]) r ++;
            for (int j = r; j >= i; j --)
                ans1[j] = sum --;
            i = r + 1;
        }
        output(ans1);
        output(ans);
    }
    return 0;
}