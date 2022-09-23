#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 5000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
vector < int > v[N];

void solve()
{
        cin >> n;
        for(int i = 1; i < n; i++){
                int x;
                cin >> x;
                v[x].push_back(i + 1);
        }
        for(int i = 1; i <= n; i++){
                if(v[i].empty()){
                        continue;
                }
                int cnt = 0;
                for(int y: v[i]){
                        cnt += v[y].size() == 0;
                }
                if(cnt < 3){
                        cout << "No" << "\n";
                        return;
                }
        }
        cout << "Yes" << "\n";
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