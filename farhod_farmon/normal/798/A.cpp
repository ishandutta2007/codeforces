#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 400200;
const long long MX = 200200;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

string s;

void solve()
{
        cin >> s;
        int cnt = 0;
        for(int i = 0; i < s.size() / 2; i++)
        {
                if(s[i] != s[s.size() - i - 1])
                {
                        cnt++;
                }
        }
        if(cnt == 0 && s.size() % 2 == 1 || cnt == 1)
        {
                cout << "YES" << endl;
        }
        else
        {
                cout << "NO" << endl;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("rmq.in");
        //fout("rmq.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}