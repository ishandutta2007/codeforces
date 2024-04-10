#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n, a[N];

bool can(long long x)
{
    long long cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] > x)
            return false;
        cnt += x - a[i];
        if(cnt >= x)
            return true;
    }
    return false;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    long long l = 0,
              r = 1e15;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        l = max(l, 1ll * a[i]);
    }
    while(l < r){
        long long m = (l + r) / 2;
        if(can(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
}