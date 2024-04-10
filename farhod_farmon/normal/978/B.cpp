#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 5050;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;

void solve()
{
        cin >> n;
        vector < char > v;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                v.push_back(c);
                int l = v.size() - 1;
                if(l >= 2 && v[l] == 'x' && v[l - 1] == 'x' && v[l - 2] == 'x'){
                        v.pop_back();
                }
        }
        cout << n - v.size() << "\n";
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