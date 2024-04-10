#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 7;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

string s;
string t = "abcdefghijklmnopqrstuvwxyz";

void solve()
{
        cin >> s;
        for(int i = 0, j = 0; i < s.size() && j < t.size(); i++){
                if(s[i] <= t[j]){
                        s[i] = t[j];
                        j++;
                }
                if(i == s.size() - 1 && j < t.size()){
                        cout << -1 << "\n";
                        return;
                }
        }
        cout << s << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}