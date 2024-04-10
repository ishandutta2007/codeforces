#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;

void solve()
{
        vector < int > v, g;
        int h = -1, hh = 1e9 + 1, s = 1;
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                if(x == 0){
                        g.push_back(i);
                }
                else if(x > 0){
                        v.push_back(i);
                }
                else if(x < 0){
                        s = -s;
                        if(- x < hh){
                                if(h != -1){
                                        v.push_back(h);
                                }
                                hh = -x;
                                h = i;
                        }
                        else{
                                v.push_back(i);
                        }
                }
        }
        if(h != -1){
                if(s < 0){
                        g.push_back(h);
                }
                else{
                        v.push_back(h);
                }
        }
        for(int i = g.size() - 1; i > 0; i--){
                cout << 1 << " " << g[i] << " " << g[0] << "\n";
        }
        if(!v.empty()){
                if(!g.empty())cout << 2 << " " << g[0] << "\n";
                for(int i = v.size() - 1; i > 0; i--){
                        cout << 1 << " " << v[i] << " " << v[0] << "\n";
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}