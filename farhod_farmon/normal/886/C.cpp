#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 10010;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
bool used[N];

void solve()
{
        cin >> n;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                if(!used[x]){
                        cnt++;
                }
                used[x] = false;
                used[i] = true;
        }
        cout << cnt << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("mine.in");
        //fout("mine.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}