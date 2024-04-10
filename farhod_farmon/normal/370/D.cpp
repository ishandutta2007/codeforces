#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 2020;

using namespace std;

int n, m, s[N][N], all;
char c[N][N];

void ans(bool b)
{
    if(b == false){
        cout << -1 << "\n";
        exit(0);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout << c[i][j];
        cout << "\n";
    }
    exit(0);
}

int get(int x1, int y1, int x2, int y2)
{
    if(x1 > x2 || y1 > y2)
        return 0;
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            if(c[i][j] == '.')
                continue;
            all++;
            s[i][j]++;
        }
    }
    if(all == 1)
        ans(true);
    int x, y, mx = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j > 1 && get(1, 1, n, j - 1) || i > 1 && get(1, 1, i - 1, m))
                break;
            int h = 0;
            int l = j, r = m;
            while(l < r){
                int mid = (l + r) / 2;
                if(get(i, j, n, mid) < all)
                    l = mid + 1;
                else
                    r = mid;
            }
            h = l - j + 1;
            l = i, r = n;
            while(l < r){
                int mid = (l + r) / 2;
                if(get(i, j, mid, j + h - 1) < all)
                    l = mid + 1;
                else
                    r = mid;
            }
            h = max(h, l - i + 1);
            if(i + h - 1 > n || j + h - 1 > m)
                continue;
            if(get(i + 1, j + 1, i + h - 2, j + h - 2) > 0)
                continue;
            if(mx == 0 || h < mx){
                mx = h;
                x = i;
                y = j;
            }
        }
    }
    if(mx == 0)
        ans(false);
    for(int i = 0; i < mx; i++){
        if(c[x][y + i] == '.')
            c[x][y + i] = '+';
        if(c[x + i][y] == '.')
            c[x + i][y] = '+';
        if(c[x + mx - 1][y + i] == '.')
            c[x + mx - 1][y + i] = '+';
        if(c[x + i][y + mx - 1] == '.')
            c[x + i][y + mx - 1] = '+';
    }
    ans(true);
}