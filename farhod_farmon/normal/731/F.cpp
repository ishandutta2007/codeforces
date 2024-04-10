#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 400200;

using namespace std;

int n;
int s[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d", &n);
    for(int i = 1; i <= n; i++){
        int x;
        sc("%d", &x);
        s[x]++;
    }
    for(int i = 1; i < N; i++)
        s[i] += s[i - 1];
    long long ans = 0;
    for(int i = 1; i < N / 2; i++){
        if(s[i] - s[i - 1] == 0)
            continue;
        long long cnt = 0;
        for(int j = i; j < N / 2; j += i)
            cnt += 1ll * j * (s[j + i - 1] - s[j - 1]);
        ans = max(ans, cnt);
    }
    pr("%I64d\n", ans);
}