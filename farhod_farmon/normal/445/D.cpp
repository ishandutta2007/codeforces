#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100100;

using namespace std;

lli x;
int n, d, i, j, h, a[N], b[N], c[N], p[N];
set < int > s;
vector < int > v;

lli getNextX()
{
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB()
{
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}


int main()
{
    int mx = sqrt(N);
    sc( "%d%d%I64d", &n, &d, &x );
    initAB();
    for( i = 0; i < n; i++ )
        p[a[i]] = i;
    for( i = 0; i < n; i++ ){
        if( b[i] )
            v.pb(i);
        s.insert(-a[i]);
        int ans = 0;
        if( v.size() < mx ){
            for( j = 0; j < v.size(); j++ ){
                if( i - v[j] >= 0 && i - v[j] <= i )
                    ans = max(ans, a[i - v[j]]);
            }
        }
        else{
            for( set < int > :: iterator it = s.begin(); it != s.end(); it++ ){
                if( b[i - p[-(*it)]] ){
                    ans = -(*it);
                    break;
                }
            }
        }
        pr( "%d\n", ans );
    }
}