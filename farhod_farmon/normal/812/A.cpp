#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 50050;
const long long MX = 10010;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int l[4];
int s[4];
int r[4];
int p[4];

void solve()
{
        bool ans = true;
        for(int i = 0; i < 4; i++){
                cin >> l[i] >> s[i] >> r[i] >> p[i];
        }
        for(int i = 0; i < 4; i++){
                if((l[i] | s[i] | r[i]) && p[i]){
                        ans = false;
                }
                if(s[i] && p[(i + 2) % 4]){
                        ans = false;
                }
                if(r[i] && p[(i + 1) % 4]){
                        ans = false;
                }
                if(l[i] && p[(i - 1 + 4) % 4]){
                        ans = false;
                }
        }
        if(ans){
                cout << "NO" << endl;
        }
        else{
                cout << "YES" << endl;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("curling.in");
        //fout("curling.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}