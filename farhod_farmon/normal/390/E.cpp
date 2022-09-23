#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 5000000;

using namespace std;

long long a[2][N];
long long b[2][N];

void add(long long g, long long x, long long y)
{
    x = x - 1;
    for(long long i = x + 1; i < N; i += i & -i){
        a[g][i] += x * y;
        b[g][i] += y;
    }
}

long long get(long long g, long long x)
{
    long long cnt = 0;
    for(long long i = x; i > 0; i -= i & -i)
        cnt += b[g][i] * x - a[g][i];
    return cnt;
}

long long n, m, w;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> w;
    long long s = 0;
    while(w--){
        long long t, x1, y1, x2, y2, v;
        cin >> t >> x1 >> y1 >> x2 >> y2;
		if(t){
            cout << get(0, x2) - get(0, x1 - 1) + get(1, y2) - get(1, y1 - 1) - s << endl;
		}
        else{
            cin >> v;
            x2 = x2 + 1;
            y2 = y2 + 1;
            s += (x2 - x1) * (y2 - y1) * v;
            add(0, x1, v * y2 - v * y1);
            add(0, x2, v * y1 - v * y2);
            add(1, y1, v * x2 - v * x1);
            add(1, y2, v * x1 - v * x2);
        }
    }
}