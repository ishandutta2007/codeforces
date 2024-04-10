#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define int long long

using namespace std;

typedef pair < pair<int,int>, int > line;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : llabs(a);
}

line getLine(int x1, int y1, int x2, int y2)
{
    int g = gcd(x1 - x2, y1 - y2);
    int kx = (x1 - x2) / g, ky = (y1 - y2) / g, b;
    if (kx < 0) kx = -kx, ky = -ky;
    if (kx == 0) ky = llabs(ky);
    b = (y1 * kx) - (ky * x1);
    return {{kx, ky}, b};
}

int f(int n)
{
    return n * (n - 1) * (n - 2) / 6;
}

vector <int> pr(4000);

int g(int n)
{
    for (int i = 0; i < 4000; i++)
        if (pr[i] == n) return i + 1;
    cout << "BUGS :( " << n << endl;
    exit(256);
}

signed main()
{
    int n; cin >> n;
    vector < pair<int,int> > v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    pr[0] = 0;
    for (int i = 1; i < 4000; i++) pr[i] = pr[i - 1] + i;

    vector <line> w;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            w.push_back(getLine(v[i].first, v[i].second, v[j].first, v[j].second));
    sort(w.begin(), w.end());

    int cnt = 1, ans = f(n);
    for (int i = 1; i < w.size(); i++)
        if (w[i] != w[i - 1]) ans -= f(g(cnt)), cnt = 1;
        else cnt++;
    ans -= f(g(cnt));

    cout << ans;
}