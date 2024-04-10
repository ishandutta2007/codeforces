#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 30030;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

ll n;
ll all;
ll a[N];
set < ll > s;

void f()
{
        s.clear();
        ll sum = 0;
        for(int i = 1; i <= n; i++){
                s.insert(a[i]);
                sum += a[i];
                if(i == 1){
                        continue;
                }
                ll sum2 = all - sum;
                if(sum > sum2){
                        if((sum - sum2) % 2){
                                continue;
                        }
                        ll need = (sum - sum2) / 2;
                        if(s.find(need) != s.end()){
                                cout << "YES" << endl;
                                exit(0);
                        }
                }
                else if(sum == sum2){
                        cout << "YES" << endl;
                        exit(0);
                }
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                all += a[i];
        }
        f();
        for(int i = 1; i <= n / 2; i++){
                swap(a[i], a[n - i + 1]);
        }
        f();
        cout << "NO" << endl;
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