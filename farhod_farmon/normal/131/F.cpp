#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 505;

using namespace std;

int n, m, g;
int d[N][N];
int s[N][N];
char c[N][N];

int main(){

	//fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
	cin >> n >> m >> g;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> c[i][j];
	for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(c[i][j] == '1' && c[i - 1][j] == '1' && c[i + 1][j] == '1' && c[i][j - 1] == '1' && c[i][j + 1] == '1')
                s[i][j] = 1;
        }
	}
	for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            d[i][j] = s[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
    long long cnt = 0;
	for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int l = 1, k = j - 2; k >= 1; k--){
                while(l <= i - 2 && d[i - 1][j - 1] - d[l][j - 1] - d[i - 1][k] + d[l][k] >= g)
                    l++;
                cnt = cnt + l - 1;
            }
        }
	}
	cout << cnt << endl;
}