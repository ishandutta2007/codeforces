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

void f(long long &a, long long &b, long long x, long long y)
{
    a = x + (y - x - x) / 2;
    b = x + (y - x - x - 1) / 2;
}

long long n;
long long a[N], b[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] + a[i] < b[i] || b[i] == 1){
            ans = ans - 1;
            continue;
        }
        long long cost_a, cost_b;
        f(cost_a, cost_b, a[i], b[i]);
        ans = ans + cost_a * cost_b;
    }
    cout << ans << endl;
}