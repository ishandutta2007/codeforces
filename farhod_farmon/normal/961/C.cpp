#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};

int n;
int ans = 1e9;
char a[5][N][N];

void f(vector < int > v, int g)
{
        int cnt = 0;
        for(int i = 0; i < v.size(); i++){
                for(int j = 1; j <= n; j++){
                        for(int h = 1; h <= n; h++){
                                int y = (j + h + g + dx[i] + dy[i]) % 2;
                                cnt += abs(a[v[i]][j][h] - y);
                        }
                }
        }
        ans = min(ans, cnt);
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= 4; i++){
                for(int j = 1; j <= n; j++){
                        for(int h = 1; h <= n; h++){
                                cin >> a[i][j][h];
                                a[i][j][h] -= '0';
                        }
                }
        }
        vector < int > v;
        for(int i = 1; i <= 4; i++){
                v.push_back(i);
        }
        do{
                f(v, 0);
                f(v, 1);
        }while(next_permutation(v.begin(), v.end()));
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}