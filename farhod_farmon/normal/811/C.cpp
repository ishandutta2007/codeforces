#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 5050;
const long long MX = 10010;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int d[N];
int l[N];
int r[N];
bool used[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(!l[a[i]]){
                        l[a[i]] = i;
                }
                r[a[i]] = i;
        }
        for(int i = 1; i <= n; i++){
                int cnt = 0, mn = i;
                d[i] = d[i - 1];
                for(int j = 1; j < N; j++){
                        used[j] = false;
                }
                for(int j = i; j >= 1; j--){
                        if(!used[a[j]]){
                                used[a[j]] = true;
                                cnt ^= a[j];
                        }
                        mn = min(mn, l[a[j]]);
                        if(r[a[j]] > i){
                                break;
                        }
                        if(mn == j){
                                d[i] = max(d[i], d[j - 1] + cnt);
                        }
                }
        }
        cout << d[n] << endl;
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