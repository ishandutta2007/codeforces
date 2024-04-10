#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 120100;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];
map < int, int > d;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                d[a[i]]++;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                d[a[i]]--;
                bool gg = true;
                for(int j = 0; j < 31; j++){
                        int x = (1 << j) - a[i];
                        if(d.find(x) != d.end() && d[x] > 0){
                                gg = false;
                        }
                }
                cnt += gg;
                d[a[i]]++;
        }
        cout << cnt << "\n";
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