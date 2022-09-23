#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 1000100;
const long long mod = 1e9 + 7;

using namespace std;

pair < long long, long long > get(long long x, long long y)
{
        pair < long long, long long > ans = {0, 0};
        if(x < 1 || y < 1){
                return ans;
        }
        long long a = (y + 1) / 2;
        long long b = y - a;
        ans.fi = (x + 1) / 2 * a;
        ans.se = (x + 1) / 2 * b;
        a = y / 2, b = y - a;
        ans.fi += x / 2 * a;
        ans.se += x / 2 * b;
        return ans;
}

pair < long long, long long > get(long long x1, long long y1, long long x2, long long y2)
{
        if(x1 > x2 || y1 > y2){
                return {0, 0};
        }
        pair < long long, long long > a = get(x2, y2);
        pair < long long, long long > b = get(x2, y1 - 1);
        pair < long long, long long > c = get(x1 - 1, y2);
        pair < long long, long long > d = get(x1 - 1, y1 - 1);
        a.fi = a.fi - b.fi - c.fi + d.fi;
        a.se = a.se - b.se - c.se + d.se;
        return a;
}

long long area(long long x1, long long y1, long long x2, long long y2)
{
        if(x1 > x2 || y1 > y2){
                return 0;
        }
        return (x2 - x1 + 1) * (y2 - y1 + 1);
}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        //freopen("nodes.in","r",stdin);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                int x1, y1, x2, y2, x3, y3, x4, y4, n, m;
                cin >> n >> m; swap(n, m);
                cin >> x1 >> y1 >> x2 >> y2;
                cin >> x3 >> y3 >> x4 >> y4;
                pair < long long, long long > a = get(1, 1, n, m);;
                pair < long long, long long > b = get(x1, y1, x2, y2);
                pair < long long, long long > c = get(x3, y3, x4, y4);
                pair < long long, long long > d = get(max(x1, x3), max(y1, y3), min(x2, x4), min(y2, y4));
                a.fi = a.fi - b.fi - c.fi + d.fi;
                a.se = a.se - b.se - c.se + d.se;
                a.fi += area(x1, y1, x2, y2);
                a.se += area(x3, y3, x4, y4);
                a.fi -= area(max(x1, x3), max(y1, y3), min(x2, x4), min(y2, y4));
                cout << a.fi << " " << a.se << "\n";
        }
}