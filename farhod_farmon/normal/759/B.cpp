#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );
#define ll int

const int N = 200200;
const long long mod = 1e15 + 3;

using namespace std;

long long n;
long long t[N];
long long s[N];
long long d[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    int h1 = 1,
        h2 = 1;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        //s[i] = s[i - 1] + t[i];
        while(s[i] - s[h1] >= 90)
            h1++;
        while(s[i] - s[h2] >= 1440)
            h2++;
        d[i] = d[i - 1] + 20;
        d[i] = min(d[i], d[h1 - 1] + 50);
        d[i] = min(d[i], d[h2 - 1] + 120);
        cout << d[i] - d[i - 1] << endl;
    }
}