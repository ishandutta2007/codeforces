#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000010;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int k;
int l[N];
int r[N];
int c[N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                r[c] = i;
                if(l[c] == 0){
                        l[c] = i;
                }
        }
        for(int i = 'A'; i <= 'Z'; i++){
                c[l[i]]++;
                c[r[i] + 1]--;
        }
        for(int i = 1; i <= n; i++){
                c[i] += c[i - 1];
                if(c[i] > k){
                        cout << "YES" << "\n";
                        return;
                }
        }
        cout << "NO" << "\n";
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