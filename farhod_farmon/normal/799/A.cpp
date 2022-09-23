#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 33;
const long long MX = 30030;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

int n, t, d, k;

void solve()
{
        cin >> n >> t >> k >> d;
        int cnt1 = 0, cnt2 = 0, c1 = 0, c2 = 0;
        while(c1 < n){
                cnt1++;
                if(cnt1 % t == 0){
                        c1 += k;
                }
        }
        while(c2 < n){
                cnt2++;
                if(cnt2 % t == 0){
                        c2 += k;
                }
                if(cnt2 > d && (cnt2 - d) % t == 0){
                        c2 += k;
                }
        }
        if(cnt2 < cnt1){
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