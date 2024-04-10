#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 10010;
const long long MX = 10010;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int q;
int a[N];

void solve()
{
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= q; i++){
                int l, r, x, cnt = 0;
                cin >> l >> r >> x;
                for(int j = l; j <= r; j++){
                        if(a[j] < a[x]){
                                cnt++;
                        }
                }
                if(l + cnt == x){
                        cout << "Yes" << endl;
                }
                else{
                        cout << "No" << endl;
                }
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