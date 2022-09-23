#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

vector < long long > s;

void rec(long long x)
{
    if(x > 1e11)
        return;
    s.pb(x);
    rec(x * 10 + 4);
    rec(x * 10 + 7);
}

long long f(long long l1, long long r1, long long l2, long long r2)
{
    l1 = max(l1, l2);
    r1 = min(r1, r2);
    return max(r1 - l1 + 1, 0ll);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    long long pl, pr, vl, vr, k;
    rec(0);
    sort(s.begin(), s.end());
    cin >> pl >> pr >> vl >> vr >> k;
    long long ans = 0;
    for(int i = 1; i + k < s.size(); i++){
        long long l1 = s[i - 1] + 1,
                  r1 = s[i],
                  l2 = s[i + k - 1],
                  r2 = s[i + k] - 1;
        long long a = f(l1, r1, vl, vr) * f(l2, r2, pl, pr);
        long long b = f(l1, r1, pl, pr) * f(l2, r2, vl, vr);
        ans += a + b;
        if(k == 1 && a > 0 && b > 0)
            ans--;
    }
    long long all = (pr - pl + 1) * (vr - vl + 1);
    cout << fixed << setprecision(12) << 1.0 * ans / all << endl;
}