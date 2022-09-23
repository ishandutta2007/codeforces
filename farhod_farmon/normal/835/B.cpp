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

int k;
string s;

void solve()
{
        int cnt = 0;
        cin >> k >> s;
        vector < int > v;
        for(int i = 0; i < s.size(); i++){
                s[i] -= '0';
                k -= s[i];
                v.push_back(9 - s[i]);
        }
        sort(v.begin(), v.end());
        for(int i = v.size() - 1; i >= 0 && k > 0; i--){
                k -= v[i];
                cnt++;
        }
        cout << cnt << "\n";
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