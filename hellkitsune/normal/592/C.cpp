#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL t, w, b;

LL gcd(LL a, LL b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int main() {
    cin >> t >> w >> b;
    double d = (double)w * b / gcd(w, b);
    if (d > t + 100) {
        LL mx = min(min(w, b) - 1, t);
        LL g = gcd(mx, t);
        mx /= g;
        t /= g;
        cout << mx << "/" << t << endl;
        return 0;
    }
    LL x = w / gcd(w, b) * b;
    LL mx = min(w, b);
    LL cnt = t / x;
    LL ansB = t;
    t -= cnt * x;
    LL ansA = cnt * mx;
    mx = min(mx - 1, t);
    ansA += mx;
    LL g = gcd(ansA, ansB);
    ansA /= g;
    ansB /= g;
    cout << ansA << "/" << ansB << endl;
    return 0;
}