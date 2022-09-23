#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 111;

using namespace std;

int n;
char c[N][N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int cnt = 0;
            cnt += (c[i - 1][j] == 'o');
            cnt += (c[i + 1][j] == 'o');
            cnt += (c[i][j - 1] == 'o');
            cnt += (c[i][j + 1] == 'o');
            if(cnt % 2){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}