#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int d[N];
string s;

void solve()
{
        cin >> s;
        s = "0" + s;
        for(int i = 1; i < s.size(); i++){
                int c = 0;
                d[i] = d[i - 1];
                for(int j = i; j >= 1; j--){
                        c = (c + s[j] - '0') % 3;
                        if(c == 0 && (s[j] != '0' || i == j)){
                                d[i] = max(d[i], d[j - 1] + 1);
                        }
                        if(i - j == 100){
                                break;
                        }
                }
        }
        cout << d[s.size() - 1] << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}