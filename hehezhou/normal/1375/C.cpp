#include <bits/stdc++.h>
using namespace std;
int t;
int n, a[300010];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        stack < int > s;
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            if (s.empty()) s.push(a[i]);
            else {
                while (s.size() > 1 && s.top() < a[i]) s.pop();
                if (a[i] < s.top()) s.push(a[i]);
            }
        }
        puts(s.size() > 1 ? "NO" : "YES");
    }
}