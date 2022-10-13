#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int n, l, r, a[100100];
long long s[100100], ql, qr;

int main()
{
    cin >> n >> l >> r >> ql >> qr;
    for (int i = 1; i <= n; i++) scanf("%d", a + i), s[i] = s[i - 1] + a[i];
    
    long long ans = min(s[n] * l + (n - 1) * ql, s[n] * r + (n - 1) * qr);
    for (int i = 1; i < n; i++)
        if (i <= n - i)
            ans = min(ans, s[i] * l + (s[n] - s[i]) * r + max(0, n - i * 2 - 1) * qr);
        else
            ans = min(ans, s[i] * l + (s[n] - s[i]) * r + max(0, n - (n - i) * 2 - 1) * ql);
        
    cout << ans << endl;
}