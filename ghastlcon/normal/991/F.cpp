#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
#define int long long
using namespace std;

map<int, string> f, g;

string Tostr(int x)
{
    char s[20];
    int i;

    for(i = 0;x;x /= 10, i ++)
        s[i] = x % 10 + 48;
    s[i] = 0;
    reverse(s, s + i);

    return s;
}

inline void Minimize(string &x, string y)
{
    if(x.size() > y.size())
        x = y;

    return;
}

signed main(void)
{
    int n;
    int i, j, m, k;
    string o;

    cin >> n;
    o = Tostr(n);

    for(i = 2;i * i <= n;i ++)
        for(j = 2, k = i * i;k <= n;j ++, k *= i)
        {
            // cout << i << '^' << j << endl;
            if(!f.count(k) || f[k].size() > Tostr(i).size() + Tostr(j).size() + 1)
                f[k] = Tostr(i) + "^" + Tostr(j);

            if(n == k)
                Minimize(o, Tostr(i) + "^" + Tostr(j));
            else
                Minimize(o, Tostr(i) + "^" + Tostr(j) + "+" + Tostr(n - k));

            if(!(n % k))
                Minimize(o, Tostr(i) + "^" + Tostr(j) + "*" + Tostr(n / k));
            else
                Minimize(o, Tostr(i) + "^" + Tostr(j) + "*" + Tostr(n / k) + "+" + Tostr(n % k));

            for(m = 2;k * m < n && m < 10;m ++)
                if(!g.count(k * m) || g[k * m].size() > Tostr(i).size() + Tostr(j).size() + 3)
                    g[k * m] = Tostr(i) + "^" + Tostr(j) + "*" + Tostr(m);
        }

    for(i = 2;i * i <= n;i ++)
        for(j = 2, k = i * i;k <= n;j ++, k *= i)
        {
            if(!(n % k) && f.count(n / k))
                Minimize(o, Tostr(i) + "^" + Tostr(j) + "*" + f[n / k]);
            if(n != k && f.count(n - k))
                Minimize(o, Tostr(i) + "^" + Tostr(j) + "+" + f[n - k]);
            if(!(n % k) && g.count(n / k))
                Minimize(o, Tostr(i) + "^" + Tostr(j) + "*" + g[n / k]);
            if(n != k && g.count(n - k))
                Minimize(o, Tostr(i) + "^" + Tostr(j) + "+" + g[n - k]);
        }

    for(m = 1, n --;m < 10;m ++, n --)
        for(i = 2;i * i <= n;i ++)
            for(j = 2, k = i * i;k <= n;j ++, k *= i)
                if(!(n % k) && f.count(n / k))
                    Minimize(o, Tostr(i) + "^" + Tostr(j) + "*" + f[n / k] + "+" + Tostr(m));

    cout << o << endl;

    return 0;
}