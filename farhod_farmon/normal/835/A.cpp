#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 3030;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int s, v1, t1, v2, t2;

void solve()
{
        cin >> s >> v1 >> v2 >> t1 >> t2;
        v1 = t1 * 2 + s * v1;
        v2 = t2 * 2 + s * v2;
        if(v1 < v2){
                cout << "First" << "\n";
        }
        else if(v1 > v2){
                cout << "Second" << "\n";
        }
        else{
                cout << "Friendship" << "\n";
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