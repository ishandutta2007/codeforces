#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 3003;
const long long Q = 10001;
const long long mod = 1e9 + 7;;
const long long block = sqrt(N);

using namespace std;

int n;
bool used[N][N];

bool ok(int a, int b, int c, int d)
{
        if(a == c || b == d){
                return false;
        }
        if(a + b == c + d || a - b == c - d){
                return false;
        }
        return true;
}

void solve()
{
        cin >> n;
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        used[x2][y2] = 1;
        queue < pair < int, int > > q;
        q.push({x2, y2});
        while(!q.empty()){
                int x = q.front().fi;
                int y = q.front().se;
                q.pop();
                for(int i = -1; i <= 1; i++){
                        for(int j = -1; j <= 1; j++){
                                int nx = x + i, ny = y + j;
                                if(nx < 1 || ny < 1 || nx > n || ny > n){
                                        continue;
                                }
                                if(used[nx][ny] == false && ok(x1, y1, nx, ny)){
                                        used[nx][ny] = 1;
                                        q.push({nx, ny});
                                }
                        }
                }
        }
        if(used[x3][y3]){
                cout << "YES" << "\n";
        }
        else{
                cout << "NO" << "\n";
        }
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