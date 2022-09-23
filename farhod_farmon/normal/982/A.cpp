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
string s;

bool can()
{
        for(int i = 0; i + 1 < n; i++){
                if(s[i] == '1' && s[i + 1] == '1'){
                        return false;
                }
        }
        return true;
}

void solve()
{
        cin >> n >> s;
        for(int i = 0; i < n; i++){
                if(s[i] == '0'){
                        s[i] = '1';
                        if(can()){
                                cout << "No" << "\n";
                                return;
                        }
                        s[i] = '0';
                }
        }
        if(can()){
                cout << "Yes" << "\n";
        }
        else{
                cout << "No" << "\n";
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