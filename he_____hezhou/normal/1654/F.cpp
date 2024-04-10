#include <bits/stdc++.h>
using namespace std;
char s[1 << 18 | 10];
int n, m;
int rk[1 << 18], sa[1 << 18], tmp[1 << 18];
int buc[1 << 18], y[1 << 18];
pair < int, int > cur[1 << 18];
int main() {
    scanf("%d", &n);
    m = 200;
    scanf("%s", s);
    for (int i = 0; i < 1 << n; i++) rk[i] = s[i] - 'a' + 1;
    for (int i = 1; i <= m; i++) buc[i] = 0;
    for (int i = 0; i < 1 << n; i++) buc[rk[i]]++;
    for (int i = 1; i <= m; i++) buc[i] += buc[i - 1];
    for (int i = 0; i < 1 << n; i++) sa[--buc[rk[i]]] = i;
    // for (int i = 0; i < 1 << n; i++) cerr << sa[i] << " \n"[i == (1 << n) - 1];
    // for (int i = 0; i < 1 << n; i++) cerr << rk[i] << " \n"[i == (1 << n) - 1];
    for (int p = 1; p < 1 << n; p <<= 1) {
        for (int i = 0; i < 1 << 18; i++) sa[i] = i, cur[i] = {rk[i], rk[i ^ p]};
        sort(sa, sa + (1 << n), [](int a, int b) {
            return cur[a] < cur[b];
        });
        m = 0;
        for (int i = 0; i < 1 << n; i++) {
            if (i == 0 || cur[sa[i]] != cur[sa[i - 1]]) rk[sa[i]] = ++m;
            else rk[sa[i]] = m;
        }
        // for (int i = 1; i <= m; i++) buc[i] = 0;
        // for (int i = 0; i < 1 << n; i++) buc[rk[i]]++;
        // for (int i = 1; i <= m; i++) buc[i] += buc[i - 1];
        // for (int i = 0; i < 1 << n; i++) tmp[i] = sa[i];
        // for (int i = 1 << n; i --> 0; ) sa[--buc[rk[tmp[i ^ p]]]] = tmp[i ^ p];
        // for (int i = 0; i < 1 << n; i++) tmp[i] = rk[i];
        // m = 0;
        // for (int i = 0; i < 1 << n; i++) {
        //     if (i == 0 || tmp[sa[i]] != tmp[sa[i - 1]] || tmp[sa[i] ^ p] != tmp[sa[i - 1] ^ p]) rk[sa[i]] = ++m;
        //     else rk[sa[i]] = m;
        // }
        // for (int i = 0; i < 1 << n; i++) cerr << sa[i] << " \n"[i == (1 << n) - 1];
        // for (int i = 0; i < 1 << n; i++) cerr << rk[i] << " \n"[i == (1 << n) - 1];
    }
    int ans = sa[0];
    for (int i = 0; i < 1 << n; i++) if ((i ^ ans) < i) swap(s[i], s[ans ^ i]);
    puts(s);
}