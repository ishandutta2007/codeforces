#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6 + 10;
char s[N];
struct node{
    int ls, rs;
}bla[N], whi[N];
int n;
int get(int mid, int l, int len) {
    int ans = 1e9;
    int tmp = l;
    if (whi[mid].ls) {
        l = max(l, mid - whi[mid].ls + 1);
        int r = mid + whi[mid].rs - 1;
        if (r - l + 1 >= len)
            ans = min(l + len - 1, ans);
    }
    l = tmp;
    if (bla[mid].ls) {
        l = max(l, mid - bla[mid].ls + 1);
        int r = mid + bla[mid].rs - 1;
        if (r - l + 1 >= len)
            ans = min(l + len - 1, ans);
    }
    return ans == 1e9? -1 : ans;
}
int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++) {
        bla[i].ls = bla[i - 1].ls + 1;
        whi[i].ls = whi[i - 1].ls + 1;
        if (s[i] == '1')
            whi[i].ls = 0;
        if (s[i] == '0')
            bla[i].ls = 0;
    }

    for (int i = n; i >= 1; i --) {
        bla[i].rs = bla[i + 1].rs + 1;
        whi[i].rs = whi[i + 1].rs + 1;
        if (s[i] == '1')
            whi[i].rs = 0;
        if (s[i] == '0')
            bla[i].rs = 0;
    }
    for (int len = 1; len <= n; len ++) {
        int cnt = 0;
        int l = 1;
        while (l + len - 1 <= n) {
            if (get(l + len - 1, l, len) != -1)
                l = get(l + len - 1, l, len) + 1, cnt ++;
            else
                l += len;
        }
        printf("%d ", cnt);
    }
    return 0;
}