#include <bits/stdc++.h>
#include <windows.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 202;

using namespace std;

long long a, b;

long long f(long long k)
{
    if(k == 1)
        return a * a - b * b;
    long long mb = (b / k) * (b / k) * (k - b % k) + (b / k + 1) * (b / k + 1) * (b % k);
    long long ma = k - 2 + (a - k + 2) * (a - k + 2);
    return ma - mb;
}

void out(long long k)
{
    long long g = b % max(k, 1ll);
    for(int i = 1; i <= k; i++){
        long long h = b / k;
        if(g){
            h++;
            g--;
        }
        if(i == k){
            for(int j = 1; j <= a - max(k, 2ll) + 2; j++)
                cout << 'o';
        }
        else if(i > 1)
            cout << 'o';
        for(int j = 1; j <= h; j++)
            cout << 'x';
    }
    exit(0);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> a >> b;
    if(b == 0){
        cout << a * a << endl;
        for(int i = 1; i <= a; i++)
            cout << 'o';
        return 0;
    }
    long long ans = 1;
    for(long long i = 2; i <= min(b, a + 1); i++)
        if(f(i) > f(ans))
            ans = i;
    cout << f(ans) << endl;
    out(ans);
}