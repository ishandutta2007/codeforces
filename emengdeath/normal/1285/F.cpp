#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
const int N = 1e5;
int a[N + 1], d[N + 1], mu[N + 1], sum[N + 1];
vector<int>w[N + 1];
int n;
long long ans;
int calc(int x) {
    long long ans = 0;
    for (int i = 1; i * i <= x; i ++)
        if (x % i == 0) {
            ans += mu[i] * sum[i];
            if (i * i != x)
                ans += mu[x / i] * sum[x / i];
        }
    return ans;
}
void add(int x, int v) {
    for (int i = 1; i * i <= x; i ++)
        if (x % i == 0) {
            sum[i] += v;
            if (i * i != x)
                sum[x / i] += v;
        }
}
void work(vector<int>&w, int gcd){
    if (w.empty()) return;
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    stack<int>s;
    for (int i = 1; i <= w[0]; i ++)
        sum[i] = 0;
    int last = 0;
    for (auto u:w) {
        if (last == u) continue;
        last = u;
        if (u == 196) {
            int yy;
            yy = 0;
        }
        int cnt = calc(u);
        while (cnt) {
            if (__gcd(s.top(), u) == 1){
                cnt --;
                ans = max(ans, 1ll * gcd * s.top() * u);
            }
            add(s.top(), -1);
            s.pop();
        }
        add(u, 1);
        s.push(u);
    }
}
int main(){
    scanf("%d", &n);
    mu[1] = 1;
    for (int i = 2; i <= N; i ++) {
        if (!a[i])
        {
            mu[i] = -1;
            d[a[i] = ++d[0]] = i;
        }
        for (int j = 1; j <= a[i] && d[j] * i <= N; j ++)
        {
            a[d[j] * i] = j;
            if (j != a[i])
                mu[d[j] * i] = -mu[i];
        }
    }
    for (int i = 1; i <= n ;i ++) {
        int x;
        scanf("%d", &x);
        ans =max(ans, 1ll * x);
        for (int j = 1; j *j <= x; j ++)
            if (x % j == 0) {
                w[j].push_back(x/ j);
                if (x != j * j)
                    w[x /j].push_back(j);
            }
    }
    for (int i = 1; i <= n; i ++)
        work(w[i], i);
    printf("%lld\n", ans);
    return 0;
}