#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;

using namespace std;

int n;
int m;
int a[N];
int l[N][15];
int last[N];
int d[N][1 << 9];

int get(int x, int g)
{
    if(g == 0)
        return 0;
    for(int i = 14; i >= 0; i--){
        if(g > (1 << i)){
            g -= (1 << i);
            x = l[x][i];
        }
    }
    return x;
}

int solve(int x)
{
    for(int i = 1; i < (1 << 8); i++)
        d[0][i] = -1;
    d[0][0] = 0;
    int ans = -1;
    if(x == 0){
        for(int i = 1; i <= n; i++){
            if(d[0][1 << a[i]] == -1){
                d[0][1 << a[i]] = 1;
                ans++;
            }
        }
        return ans + 1;
    }
    for(int i = 1; i <= n; i++){
        int j1 = get(i, x),
            j2 = get(i, x + 1);
        for(int h = 0; h < (1 << 8); h++)
            d[i][h] = d[i - 1][h];
        for(int h = 0; h < (1 << 8); h++){
            if(h & (1 << a[i]))
                continue;
            if(j1 && d[j1 - 1][h] != -1)
                d[i][h | (1 << a[i])] = max(d[i][h | (1 << a[i])], d[j1 - 1][h] + x);
            if(j2 && d[j2 - 1][h] != -1)
                d[i][h | (1 << a[i])] = max(d[i][h | (1 << a[i])], d[j2 - 1][h] + x + 1);
        }
    }
    return d[n][(1 << 8) - 1];
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = a[i] - 1;
        l[i][0] = last[a[i]];
        last[a[i]] = i;
    }
    for(int h = 1; h < 15; h++)
        for(int i = 1; i <= n; i++)
            l[i][h] = l[l[i][h - 1]][h - 1];
    int left = 0,
        right = n / 8;
    while(left < right){
        int mid = (left + right ) / 2;
        if(solve(mid + 1) != -1)
            left = mid + 1;
        else
            right = mid;
    }
    cout << solve(left) << endl;
}