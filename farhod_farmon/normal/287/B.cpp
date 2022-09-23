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

pair < long long, long long > get(long long n, long long k)
{
    long long l = 1, r = k;
    while(l < r){
        long long m = (l + r) / 2 + 1;
        long long cnt = k * (k + 1) / 2 - (k - m) * (k - m + 1) / 2;
        if(cnt <= n)
            l = m;
        else
            r = m - 1;
    }
    return {k * (k + 1) / 2 - (k - l) * (k - l + 1) / 2, l};
}

long long n, k;

int main()
{
	//fin("input.txt");
    //fout("output.txt");
    cin >> n >> k;
    long long cnt = 0;
    k = k - 1;
    n = n - 1;
    for(long long i = min(n, k); i >= 1 && n; i = min(n, i)){
        auto p = get(n, i);
        cnt += p.se;
        n -= p.fi;
        i -= p.se;
    }
    if(n != 0)
        cnt = -1;
    cout << cnt << endl;
}