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
const long long MX = 1000010;
const long long H = 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int A;
int c[MX];
bool dead[MX];
set < pair < int, int > > B;

void solve()
{
        cin >> n >> A;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                if(x == A){
                        cnt++;
                }
                else if(dead[x] == false && (c[x] >= cnt)){
                        B.erase({c[x], x});
                        c[x]++;
                        B.insert({c[x], x});
                }
                while(!B.empty() && B.begin()->fi < cnt){
                        dead[B.begin()->se] = true;
                        B.erase(B.begin());
                }
        }
        if(cnt == 0){
                cout << (A == 1 ? 2 : 1) << "\n";
        }
        else{
                if(B.empty()){
                        cout << -1 << "\n";
                }
                else{
                        cout << B.begin()->se << "\n";
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                sc("%d", &TE);
        while(TE--)
                solve();
        return 0;
}