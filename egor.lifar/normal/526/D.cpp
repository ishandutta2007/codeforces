#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_set>


using namespace std;


#define M 1000000009
#define M1 1000000007
#define P 10007
#define P1 424243


int n, k;
string s;
int ss = 1;
int h[1000000], h1[1000000];
int p[1000001];
long long p1[1000001];
int d[5000001];
int mod[5000001];


int gethash(int l, int r) {
    return (1LL * h[r] + M - ((l > 0 ? 1LL * h[l - 1]: 0) * p[r - l + 1]) % M) % M;
}


// int gethash1(int l, int r) {
//     return (1LL * h1[r]  - ((l > 0 ? 1LL * h1[l - 1]: 0) * p1[r - l + 1])) % M;
// }


void push(int v) {
    d[v] += mod[v];
    d[v] = min(d[v], 1000000000);
    mod[v * 2] += mod[v] / 2;
    mod[v * 2] = min(mod[v * 2], 1000000000);
    mod[v * 2 + 1] += mod[v] / 2;
    mod[v * 2 + 1] = min(mod[v * 2 + 1], 1000000000);
    mod[v] = 0;
}


void add(int v, int vl, int vr, int l, int r) {
    if (vr < l || vl > r) {
        return;
    }
    if (l <= vl && vr <= r) {
        mod[v] += (vr - vl + 1);
        mod[v] = min(mod[v], 1000000000);
        return;
    }
    push(v);
    add(v * 2, vl, (vl + vr) / 2, l, r);
    add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
    d[v] = d[v * 2] + d[v * 2 + 1];
}


int main() {
    cin >> n >> k;
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            printf("1");
        }
        printf("\n");
        return 0;
    }
    cin >> s;
    while (ss < n) {
        ss *= 2;
    }
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = (1LL * p[i - 1] * P) % M;
    }
    // p1[0] = 1;
    // for (int i = 1; i <= n; i++) {
    //     p1[i] = (1LL * p1[i - 1] * P1);
    // }
    for (int i = 0; i < n; i++) {
        h[i] = ((i > 0 ? 1LL * h[i - 1]: 0) * P + 1LL * s[i]) % M;
    }
    // for (int i = 0; i < n; i++) {
    //     h1[i] = ((i > 0 ? 1LL * h1[i - 1]: 0) * P1 + 1LL * s[i]);
    // }
    for (int i = 1; i <= n; i++) {
        int j = 0;
        while (j / i < k && j + i - 1 < n && gethash(j, j + i - 1) == gethash(0, i - 1)) {
            j += i;
        }
        if (j == i * k) { 
            int l = j - 1;
            int r = min(n - 1, j + i - 1);
            while (l != r) {   
                int m = (l + r + 1) / 2;
                if (m == j - 1) {
                    l = j - 1;
                } else {
                    if (gethash(j, m) == gethash(0, m - j)) {
                        l = m;
                    }  else {
                        r = m - 1;
                    }
                }
            }
            //cout << j << endl;
         //   if (s[j] == s[0]) {
               // cout << i << endl;
                add(1, 1, ss, j, l + 1);
           // }
        }
    }
    for (int i = 1; i < 2 * ss; i++) {
        push(i);
    }
    for (int i = 0; i < n; i++) {
        if (d[ss + i] > 0LL) {
            printf("1");
        } else {
            printf("0");
        }
    }
    cout << endl;
    return 0;
}