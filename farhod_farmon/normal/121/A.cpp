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

const int N = 110;

using namespace std;

long long l, r;
vector < long long > v;

void build(long long x)
{
    if(l <= x)
        v.pb(x);
    if(x > r)
        return;
    build(x * 10 + 4);
    build(x * 10 + 7);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> l >> r;
    build(0);
    sort(v.begin(), v.end());
    long long last = l - 1,
              cnt = 0;
    for(auto x: v){
        cnt += max(0ll, min(x, r) - last) * x;
        last = x;
        if(x >= r)
            break;
    }
    cout << cnt << endl;
}