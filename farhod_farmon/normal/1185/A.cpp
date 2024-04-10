#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);
        if(a > b) swap(a, b);
        assert(a <= b && a <= c);
        cout << max(0ll, b + d - c) + max(0ll, a - b + d) << "\n";
}