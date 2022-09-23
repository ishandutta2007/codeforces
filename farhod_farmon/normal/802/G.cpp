#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1555;
const long long MX = 10010;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

string s;
string need = "heidi";
bool used[10];

void solve()
{
        cin >> s;
        for(int i = 0; i < s.size(); i++){
                for(int j = need.size() - 1; j >= 0; j--){
                        if(s[i] == need[j] && (j == 0 || used[j - 1])){
                                used[j] = true;
                        }
                }
        }
        if(used[need.size() - 1]){
                cout << "YES" << endl;
        }
        else{
                cout << "NO" << endl;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}