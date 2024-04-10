#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 110;

using namespace std;

int n, m;
char c[N][N];

char get(int i, int j)
{
    if(c[i][j] != 'Z' + 1)
        return c[i][j];
    for(char x = 'A'; x <= 'Z'; x++){
        if(c[i - 1][j] == x)
            continue;
        if(c[i][j - 1] == x)
            continue;
        if(c[i + 1][j] == x)
            continue;
        if(c[i][j + 1] == x)
            continue;
        return x;
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            c[i][j] = 'Z' + 1;
    for(int i = 1; i <= n; i++){
        vector < int > v;
        for(int j = 1; j <= m; j++){
            int g = 0;
            char t = get(i, j);
            if(c[i][j] != 'Z' + 1)
                continue;
            while(i + g <= n && j + g <= m && get(i, j + g) == t)
                g++;
            for(int ni = i; ni < i + g; ni++)
                for(int nj = j; nj < j + g; nj++)
                    c[ni][nj] = t;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout << c[i][j];
        cout << endl;
    }
}