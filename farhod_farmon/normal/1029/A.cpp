#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 200200;
const long long mod = 998244353;
const long long MAGIC = sqrt(N);

using namespace std;

int n;
int k;
char s[N];
char t[N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> s[i];
        }
        for(int i = 1; i < N; i++){
                t[i] = '*';
        }
        for(int i = 1; k > 0; i++){
                bool good = true;
                for(int j = 0; j < n; j++){
                        if(t[i + j] != '*' && t[i + j] != s[j + 1]){
                                good = false;
                        }
                }
                if(good == true){
                        for(int j = 0; j < n; j++){
                                t[i + j] = s[j + 1];
                        }
                        k--;
                }
        }
        for(int i = 1; t[i] != '*'; i++){
                cout << t[i];
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}