#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> P;
int n;
long long T, cur;
double mx, prob;
vector<P> _V, V;

P operator * (P A, P B) {
    return P(A.first * B.first, A.second + A.first * B.second);
}

P qp(P x, long long k) {
    P z(1, 0);
    for (; k; k >>= 1, x = x * x) {
        if (k & 1) z = z * x;
    }
    return z;
}

int main() {
    scanf("%d %lld", &n, &T);
    for (int i = 1, a, b; i <= n; i++) {
        double p; scanf("%d %d %lf", &a, &b, &p);
        _V.emplace_back(p, a * p), mx = max(mx, b * p);
    }
    sort(_V.begin(), _V.end(), greater<P>());
    for (auto p : _V) {
        p.second -= mx;
        if (V.empty() || p.second > V.back().second) V.push_back(p);
    }
    reverse(V.begin(), V.end());
    for (int i = 0; i < V.size(); i++) {
        long long l = cur + 1, r = T, pos = cur;
        double a = 1 - V[i].first, b = V[i].second, foo = prob;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            P mat = qp(P(a, b), mid - cur - 1);
            double p = prob * mat.first + mat.second;
            double bar = a * p + b;
            double baz = i == V.size() - 1 ? -1e18 : ((1 - V[i + 1].first) * p + V[i + 1].second);
            if (bar > baz) l = (pos = mid) + 1, foo = bar;
            else r = mid - 1;
        }
        cur = pos, prob = foo;
    }
    printf("%.6f\n", prob + T * mx);
    return 0;
}