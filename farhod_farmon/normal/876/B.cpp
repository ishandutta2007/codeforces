#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n, m, k;
vector < int > v[N];

void solve()
{
        cin >> n >> k >> m;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                v[x % m].push_back(x);
        }
        for(int i = 0; i < m; i++){
                if(v[i].size() >= k){
                        cout << "Yes" << "\n";
                        for(int j = 0; j < k; j++){
                                cout << v[i][j] << " ";
                        }
                        cout << "\n";
                        return;
                }
        }
        cout << "No" << "\n";
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}