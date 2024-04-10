#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;

using namespace std;

int n = 2, k;
int x[N], y[N];
bool used[N][N];

void f(int g)
{
    vector < int > v;
    v.pb(x[g]);
    for(int i = 1; i <= 30 - g; i++)
        v.pb(++n);
    v.pb(2);
    for(int i = 0; i + 1 < v.size(); i++)
        used[v[i]][v[i + 1]] = true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> k;
    for(int i = 0; i <= 30; i++)
        x[i] = ++n;
    for(int i = 0; i <= 30; i++)
        y[i] = ++n;
    used[1][x[0]] = used[1][y[0]] = true;
    for(int i = 0; i < 30; i++){
        used[x[i]][x[i + 1]] = true;
        used[x[i]][y[i + 1]] = true;
        used[y[i]][x[i + 1]] = true;
        used[y[i]][y[i + 1]] = true;
    }
    for(int i = 0; i <= 30; i++)
        if(k & (1 << i))
            f(i);
    cout << n << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(used[i][j] || used[j][i])
                cout << "Y";
            else
                cout << "N";
        }
        cout << "\n";
    }
}