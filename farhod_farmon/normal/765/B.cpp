#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 110;
const int MX = 300300;
const long long mod = 1e9 + 7;

using namespace std;

string s;
bool used[200];

void solve()
{
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        for(char c = 'a'; c < s[i]; c++){
            if(used[c] == false){
                cout << "NO" << endl;
                return;
            }
        }
        used[s[i]] = true;
    }
    cout << "YES" << endl;
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("friendcross.in");
    //fout("friendcross.out");
    ios_base::sync_with_stdio(0);
    int TE = 1;
    if(mtest)
        cin >> TE;
    while(TE--)
        solve();
}