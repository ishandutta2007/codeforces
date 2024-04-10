#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>


using namespace std;


#define M 1000000007
#define P 424243
#define M1 1000000009
#define P1 1000007


int n, m;
long long l[200001];
char c[200001];
long long l1[200001];
char c1[200001];
int h[200001];
int p[200001];
int h1[200001];
int p1[200001];


int gethash(int l, int r) {
    return (h[r] - (l > 0 ? 1LL * h[l - 1] * p[r - l + 1]: 0) % M + M) % M;
}

int gethash1(int l, int r) {
    return (h1[r] - (l > 0 ? 1LL * h1[l - 1] * p1[r - l + 1]: 0) % M1 + M1) % M1;
}


int main() {
    scanf("%d %d", &n, &m);
    int n1 = 0;
    for (int i = 0; i < n; i++) {
        int l2;
        scanf("%d-", &l2);
        string s;
        cin >> s;
        char c2 = s[0];
        if (i == 0) {
            l[0] = l2;
            c[0] = c2;
            n1++;
        } else {
            if (c2 != c[n1 - 1]) {
                l[n1] = l2;
                c[n1] = c2;
                n1++; 
            } else {
                l[n1 - 1] += l2;
            }
        }
    }
    n = n1;
    int m1 = 0;
    for (int i = 0; i < m; i++) {
        int l2;
        scanf("%d-", &l2);
        string s;
        cin >> s;
        char c2 = s[0];
        if (i == 0) {
            l1[0] = l2;
            c1[0] = c2;
            m1++;
        } else {
            if (c2 != c1[m1 - 1]) {
                l1[m1] = l2;
                c1[m1] = c2;
                m1++; 
            } else {
                l1[m1 - 1] += l2;
            }
        }
    }
    m = m1;
    if (m == 1) {
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (c1[0] == c[i]) {
                ans += max(0LL, l[i] - l1[0] + 1);
            }
        }
        cout << ans << endl;
        return 0;
    }
    if (m == 2) {
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (c1[0] == c[i]) {
                if (c1[1] == c[i + 1]) {
                    if (l[i] >= l1[0] && l[i + 1] >= l1[1]) {
                        ans++;
                    } 
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
    if (n < m) {
        cout << 0 << endl;
        return 0;
    }
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = (1LL * p[i - 1] * P) % M;
    }
    for (int i = 0; i < n; i++) {
        h[i] = ((i != 0 ? 1LL * h[i - 1] * P: 0) % M + l[i] + c[i]) % M;
    }
    p1[0] = 1;
    for (int i = 1; i <= n; i++) {
        p1[i] = (1LL * p1[i - 1] * P1) % M1;
    }
    for (int i = 0; i < n; i++) {
        h1[i] = ((i != 0 ? 1LL * h1[i - 1] * P1: 0) % M1 + l[i] + c[i]) % M1;
    }
    int ht = 0;
    for (int i = 1; i < m - 1; i++) {
        ht = ((1LL * ht * P) % M + l1[i] + c1[i]) % M;
    }
    int ht1 = 0;
    for (int i = 1; i < m - 1; i++) {
        ht1 = ((1LL * ht1 * P1) % M1 + l1[i] + c1[i]) % M1;
    }
    int ans = 0;
    for (int i = 0; i <= n - m; i++) {
        if (c[i] == c1[0] && l[i] >= l1[0]) {
            if (c[i + m - 1] == c1[m - 1] && l[i + m - 1] >= l1[m - 1]) {
                if (gethash(i + 1, i + m - 2) == ht && gethash1(i + 1, i + m - 2) == ht1) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}