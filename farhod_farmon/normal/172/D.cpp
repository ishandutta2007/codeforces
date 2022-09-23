#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 10000011;

using namespace std;

long long d[N];
vector < long long > v[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    for(long long i = 1; i * i < N; i++)
        d[i * i] = 1;
    for(long long i = 1; i < N; i++){
        if(d[i] != 1)
            continue;
        for(long long j = i + i, g = 1; j < N; j += i, g++){
            if(!d[j] || d[j] > d[i] + g)
                d[j] = d[i] + g;
        }
    }
    long long ans = 0,
              n,
              a;
    cin >> a >> n;
    for(long long i = a; i < a + n; i++)
        ans += d[i];
    cout << ans << endl;
}