#include <bits/stdc++.h>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int n, i, j, d[100][100], cnt[2];
string s, t;
char a = '0', b = '1';

int main()
{
    cin >> n >> s >> t;
    n = n * 2;
    for( i = 0; i < n; i++ )d[s[i]][t[i]]++;
    for( i = 0; i < n; i++ ){
        if( i % 2 == 0 ){
            if( d[b][b] ){
                d[b][b]--;
                cnt[0]++;
            }
            else if( d[b][a] ){
                d[b][a]--;
                cnt[0]++;
            }
            else if( d[a][b] )d[a][b]--;
        }
        else{
            if( d[b][b] ){
                d[b][b]--;
                cnt[1]++;
            }
            else if( d[a][b] ){
                d[a][b]--;
                cnt[1]++;
            }
            else if( d[b][a] )d[b][a]--;
        }
    }
    if( cnt[0] > cnt[1] )cout << "First" << endl;
    else if( cnt[0] < cnt[1] )cout << "Second" << endl;
    else cout << "Draw" << endl;
}