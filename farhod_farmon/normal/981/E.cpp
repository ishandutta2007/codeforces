#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 10010;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int k;
int d[N];
unsigned long long t[N];
bool used[N];
vector < int > in[N];
vector < int > out[N];

void solve()
{
        cin >> n >> k;
        //n = 10000;
        //k = 10000;
        for(int i = 1; i <= k; i++){
                int l, r, x;
                cin >> l >> r >> x;
                //l = 1;
                //r = 2;
                //x = 1;
                in[l].push_back(x);
                out[r].push_back(x);
        }
        d[0] = 1;
        t[0] = 1;
        for(int i = 1; i <= n; i++){
                for(int x: in[i]){
                        for(int j = n; j >= x; j--){
                                d[j] += d[j - x];
                                t[j] += t[j - x];
                                if(d[j] >= mod){
                                        d[j] -= mod;
                                }
                        }
                }
                for(int j = 1; j <= n; j++){
                        if(d[j] > 0 || t[j] > 0){
                                used[j] = 1;
                        }
                }
                for(int x: out[i]){
                        for(int j = x; j <= n; j++){
                                d[j] -= d[j - x];
                                t[j] -= t[j - x];
                                if(d[j] < 0){
                                        d[j] += mod;
                                }
                        }
                }
        }
        vector < int > v;
        for(int i = 1; i <= n; i++){
                if(used[i]){
                        v.push_back(i);
                }
        }
        cout << v.size() << "\n";
        for(int x: v){
                cout << x << " ";
        }
        //cout << endl;
        //scout << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}