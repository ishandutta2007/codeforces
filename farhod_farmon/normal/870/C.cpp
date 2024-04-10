#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int q;
int d[1001];
vector < int > v;

void solve()
{
        for(int i = 2; i <= 500; i++){
                int cnt = 0;
                for(int j = 2; j < i; j++){
                        if(i % j == 0){
                                cnt++;
                        }
                }
                if(cnt){
                        v.push_back(i);
                }
        }
        d[1] = d[2] = d[3] = -1;
        for(int i = 4; i <= 1000; i++){
                d[i] = -1;
                for(auto x: v){
                        if(i >= x && d[i - x] != -1){
                                d[i] = max(d[i], d[i - x] + 1);
                        }
                }
        }
        cin >> q;
        for(int i = 1; i <= q; i++){
                int n;
                int mx = -1;
                cin >> n;
                if(n <= 1000){
                        cout << d[n] << "\n";
                        continue;
                }
                for(int i = 4; i <= 1000; i++){
                        if(d[i] != -1 && (n - i) % 4 == 0){
                                mx = max(mx, d[i] + (n - i) / 4);
                        }
                }
                cout << mx << "\n";
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
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}