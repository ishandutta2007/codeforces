#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 400400;
const long long Q = 500500;
const long long mod = 1e9 + 7;
const long long MAGIC = sqrt(N);

using namespace std;

int n;
int t[N];
int x[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                string s;
                cin >> s >> x[i];
                if(s == "ADD"){
                        t[i] = 1;
                }
                else{
                        t[i] = 2;
                }
        }
        set < int > a, b, o;
        long long ans = 1;
        for(int i = 1; i <= n; i++){
                int g = x[i];
                if(t[i] == 1){
                        if(!a.empty() && g < *(--a.end())){
                                a.insert(g);
                        }
                        else if(!b.empty() && g > *b.begin()){
                                b.insert(g);
                        }
                        else{
                                o.insert(g);
                        }
                }
                else{
                        if(o.find(g) != o.end()){
                                ans = (ans + ans);
                                if(ans >= mod){
                                        ans -= mod;
                                }
                                o.erase(g);
                                while(!o.empty() && *(--o.end()) > g){
                                        b.insert(*(--o.end()));
                                        o.erase(--o.end());
                                }
                                while(!o.empty()){
                                        a.insert(*o.begin());
                                        o.erase(o.begin());
                                }
                        }
                        else{
                                if(!a.empty() && a.find(g) != a.end()){
                                        int g1 = *(--a.end());
                                        a.erase(--a.end());
                                        if(g1 != g){
                                                cout << 0 << "\n";
                                                exit(0);
                                        }
                                        while(!o.empty()){
                                                b.insert(*o.begin());
                                                o.erase(o.begin());
                                        }
                                }
                                else{
                                        int g1 = *b.begin();
                                        b.erase(b.begin());
                                        if(g1 != g){
                                                cout << 0 << "\n";
                                                exit(0);
                                        }
                                        while(!o.empty()){
                                                a.insert(*o.begin());
                                                o.erase(o.begin());
                                        }
                                }
                        }
                }
        }
        ans = (ans * (o.size() + 1)) % mod;
        cout << ans << "\n";
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