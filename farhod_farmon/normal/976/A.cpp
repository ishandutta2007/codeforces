#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int n;
char c[N];

void solve()
{
        cin >> n;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
                cnt += c[i] == '0';
        }
        cnt -= c[1] == '0';
        cout << c[1];
        while(cnt){
                cout << '0';
                cnt--;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}