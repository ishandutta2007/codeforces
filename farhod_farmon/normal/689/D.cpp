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

const int N = 200200;

using namespace std;

int L[N], mn[18][N], mx[18][N], n, a[N], b[N];

int getmin(int l, int r)
{
    int g = L[r - l + 1];
    return min(mn[g][l], mn[g][r - (1 << g) + 1]);
}

int getmax(int l, int r)
{
    int g = L[r - l + 1];
    return max(mx[g][l], mx[g][r - (1 << g) + 1]);
}

int main()
{
    //freopen( "angry.in", "r", stdin );
    //freopen( "angry.out", "w", stdout );
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> mx[0][i];
    for(int i = 1; i <= n; i++)
        cin >> mn[0][i];
    for(int i = 2; i <= n; i++)
        L[i] = L[i / 2] + 1;
    for(int i = 1; i < 18; i++){
        for(int j = 1; j <= n; j++){
            mn[i][j] = mn[i - 1][j];
            mx[i][j] = mx[i - 1][j];
            if(j + (1 << i - 1) <= n){
                mn[i][j] = min(mn[i][j], mn[i - 1][j + (1 << i) / 2]);
                mx[i][j] = max(mx[i][j], mx[i - 1][j + (1 << i) / 2]);
            }
        }
    }
    lli ans = 0;
    for(int i = 1; i <= n; i++){
        int l = i,
            r = n;
        while(l < r){
            int m = (l + r) / 2;
            if(getmax(i, m + 1) < getmin(i, m + 1))
                l = m + 1;
            else
                r = m;
        }
        int l2 = i,
            r2 = n;
        while(l2 < r2){
            int m2 = (l2 + r2) / 2;
            if(getmax(i, m2 + 1) <= getmin(i, m2 + 1))
                l2 = m2 + 1;
            else
                r2 = m2;
        }
        ans += l2 - l;
        if(getmax(i, l) == getmin(i, l))
            ans++;
    }
    cout << ans << endl;
}