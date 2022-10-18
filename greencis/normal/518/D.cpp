#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,t;
ld p;
char u[2005][2005];
ld dp[2005][2005]; /// people in queue/time left

ld f(int curn, int curt) {
    if (curt == 0) return n - curn;
    if (curn == 0) return n;
    if (!u[curn][curt]) {
        u[curn][curt] = 1;
        dp[curn][curt] = f(curn-1, curt-1) * p + f(curn, curt-1) * (1-p);
    }
    return dp[curn][curt];
}

int main()
{
    cin >> n >> p >> t;
    cout.precision(17);
    cout << fixed << f(n, t);

    return 0;
}