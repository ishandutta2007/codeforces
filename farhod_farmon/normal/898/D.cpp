#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 1000010;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n, k, m;
int a[N];

void solve()
{
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int cnt = 0;
        deque < int > d;
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++){
                d.push_back(a[i]);
                while(d.back() - d.front() >= m){
                        d.pop_front();
                }
                while(d.size() >= k){
                        d.pop_back();
                        cnt++;
                }
        }
        cout << cnt << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}