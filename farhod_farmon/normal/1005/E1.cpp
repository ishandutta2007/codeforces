#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 400200;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
int a[N];
int b[N];
unordered_map < int, unordered_map < int, int > > d;

void upd(int x, int y)
{
        x += N / 2;
        y += N / 2;
        for(int i = x; i < N; i += i & -i){
                for(int j = y; j < N; j += j & -j){
                        d[i][j]++;
                }
        }
}

int get(int x, int y)
{
        x += N / 2;
        y += N / 2;
        int cnt = 0;
        for(int i = x; i > 0; i -= i & -i){
                if(d.find(i) == d.end()){
                        continue;
                }
                for(int j = y; j > 0; j -= j & -j){
                        if(d[i].find(j) == d[i].end()){
                                continue;
                        }
                        cnt += d[i][j];
                }
        }
        return cnt;
}

void solve()
{
        cin >> n >> m;
        for(int i = 1, j = 0; i <= n; i++){
                int x;
                cin >> x;
                a[i] = a[i - 1] + (x >= m ? 1 : -1);
                b[i] = b[i - 1] + (x <= m ? 1 : -1);
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++){
                upd(a[i - 1], b[i - 1] - 1);
                ans += get(a[i] - 1, b[i] - 1);
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}