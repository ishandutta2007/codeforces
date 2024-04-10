#include <bits/stdc++.h>
using namespace std;
char s[300010];
int a[300010], tmp[300010];
int n;
int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (s[i] == ')' ? -1 : 1);
    }
    if(a[n] != 0) return puts("0\n1 1"), 0;
    int now = 0, _min = 2e9;
    int ans, ansl, ansr;
    for(int i = 1; i <= n; i++) _min = min(_min, a[i]);
    for(int i = 1; i <= n; i++) now += a[i] == _min;
    ans = now, ansl = 1, ansr = 1;
    int l, r;
    for(int i = 1; i <= n; i++) {
        if(s[i] == ')') l = i;
        if(a[i] == _min) break;
    }
    for(int i = n; i >= 1; i--) {
        if(a[i] == _min) break;
        if(s[i] == '(') r = i;
    }
    if(l == 0 || r == 0);
    else {
        swap(s[l], s[r]);
        for(int i = 1; i <= n; i++) {
            tmp[i] = tmp[i - 1] + (s[i] == ')' ? -1 : 1);
        }
        int now = 0, _min = 2e9;
        for(int i = 1; i <= n; i++) _min = min(_min, tmp[i]);
        for(int i = 1; i <= n; i++) now += tmp[i] == _min;
        swap(s[l], s[r]);
        if(now > ans) ans = now, ansl = l, ansr = r;
    }
    l = r = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == ')') l = i;
        if(a[i] == _min || a[i] == _min + 1) break;
    }
    for(int i = n; i >= 1; i--) {
        if(a[i] == _min || a[i] == _min + 1) break;
        if(s[i] == '(') r = i;
    }
    if(l == 0 || r == 0);
    else {
        swap(s[l], s[r]);
        for(int i = 1; i <= n; i++) {
            tmp[i] = tmp[i - 1] + (s[i] == ')' ? -1 : 1);
        }
        int now = 0, _min = 2e9;
        for(int i = 1; i <= n; i++) _min = min(_min, tmp[i]);
        for(int i = 1; i <= n; i++) now += tmp[i] == _min;
        swap(s[l], s[r]);
        if(now > ans) ans = now, ansl = l, ansr = r;
    }
    for(int i = 0; i <= n; i++) {
        l = i, r = i;
        for(; r <= n; r++) if(a[r] == _min || a[r] == _min + 1) break;
        i = r;
        for(; s[l] != '(' && l <= n; l++);
        for(; s[r] != ')' && r > 0; r--);
        if(l >= r) continue;
        int delta = 0;
        for(int j = l; j < r; j++) {
            if(a[j] == _min + 2) delta++;
        }
        if(delta + now > ans) ans = delta + now, ansl = l, ansr = r;
    }
    for(int i = 0; i <= n; i++) {
        l = i, r = i;
        for(; r <= n; r++) if(a[r] == _min) break;
        i = r;
        for(; s[l] != '(' && l <= n; l++);
        for(; s[r] != ')' && r > 0; r--);
        if(l >= r) continue;
        int now = 0;
        for(int j = l; j < r; j++) {
            if(a[j] == _min + 1) now++;
        }
        if(now > ans) ans = now, ansl = l, ansr = r;
    }
    cout << ans << endl << ansl << ' ' << ansr << endl;
}