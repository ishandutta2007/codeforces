#include <bits/stdc++.h>

#define MN 100100
#define INF 12345678901234567

using namespace std;
typedef long long ll;

int n, pointer = 0;
ll a[MN], b[MN], dp[MN];

struct line {
    ll a, b;
    /// a = b[i]   b = dp[i]
    line(ll a, ll b): a(a), b(b) {}
};

double intersect(line a, line b) {
    ///a1x + b1 = a2x + b2
    ///(a1 - a2)x = b2 - b1
    return 1.0 * (b.b - a.b) / (a.a - b.a);
}

vector <line> hull;

void add(line a) {
    while(hull.size() > 1 &&
          intersect(a, hull[hull.size()-2])
           < intersect(hull[hull.size()-1], hull[hull.size()-2])) {
        hull.pop_back();
    }
    hull.push_back(a);
}

ll query(ll x) {
    if(pointer >= hull.size()) {
        pointer = hull.size() - 1;
    }

    while(pointer < hull.size() - 1 &&
          (hull[pointer].a * x + hull[pointer].b
           > hull[pointer+1].a * x + hull[pointer+1].b)) {
            pointer++;
    }

    return hull[pointer].a * x + hull[pointer].b;
}

int main() {
    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        scanf("%lld",&a[i]);
    }

    for(int i=0;i<n;i++) {
        scanf("%lld",&b[i]);
    }

    dp[0] = 0;
    hull.push_back(line(b[0], 0));

    for(int i=1;i<n;i++) {
        dp[i] = query(a[i]);
        add(line(b[i], dp[i]));
    }

    printf("%lld\n",dp[n-1]);

    return 0;
}