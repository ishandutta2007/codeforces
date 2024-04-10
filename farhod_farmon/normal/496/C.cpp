#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200100;

using namespace std;

int n, m;
char c[101][101];
bool used[101];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> c[i][j];
    for(int h = 1; h <= 100; h++){
        for(int i = n; i >= 2; i--){
            for(int j = 1; j <= m; j++){
                if(used[j])
                    continue;
                if(c[i][j] < c[i - 1][j])
                    used[j] = true;
                if(c[i][j] > c[i - 1][j])
                    break;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= m; i++)
        cnt += used[i];
    cout << cnt << endl;
}