#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 1e4 + 1;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int a[N];

void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[x]++;
    }
    ll cnt = 0;
    for(int i = 0; i < MX; i++){
        if(k == 0){
            cnt += 1ll * a[i] * (a[i] - 1) / 2;
            continue;
        }
        for(int j = i + 1; j < MX; j++){
            int x = i ^ j;
            if(__builtin_popcount(x) == k)
                cnt += 1ll * a[i] * a[j];
        }
    }
    cout << cnt << endl;
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("friendcross.in");
    //fout("friendcross.out");
    ios_base::sync_with_stdio(0);
    int TE = 1;
    if(mtest)
        cin >> TE;
    while(TE--)
        solve();
}