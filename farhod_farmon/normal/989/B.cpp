#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int k;
string s;

void solve()
{
        cin >> n >> k >> s;
        bool good = false;
        for(int i = 0; i < n; i++){
                if(i - k >= 0){
                        if(s[i] == '.'){
                                if(s[i - k] == '.'){
                                        s[i - k] = '0';
                                }
                                s[i] = 1 - (s[i - k] - '0') + '0';
                        }
                        else{
                                if(s[i - k] == '.'){
                                        s[i - k] = 1 - (s[i] - '0') + '0';
                                }
                        }
                        good |= (s[i] != s[i - k]);
                }
        }
        if(!good){
                cout << "No" << "\n";
                return;
        }
        for(int i = 0; i < n; i++){
                if(s[i] == '.'){
                        s[i] = '0';
                }
                cout << s[i];
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