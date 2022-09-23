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

const int N = 505;

using namespace std;

vector < int > ans;
bool d[N + N][N + N];
int n, k;

int main()
{
    cin >> n >> k;
    d[0][0] = true;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for(int j = k; j >= 0; j--){
            for(int h = k; h >= 0; h--){
                d[j + x][h] |= d[j][h];
                d[j + x][h + x] |= d[j][h];
            }
        }
    }
    for(int i = 0; i <= k; i++)
        if(d[k][i])
            ans.pb(i);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}