#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 100100;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;

bool off = false;

string get()
{
        string res = "";
        if(off){
                for(int i = 0; i < n; i++){
                        if(i % 2){
                                res += "1";
                        } else{
                                res += "0";
                        }
                }
        } else{
                cin >> res;
        }
        return res;
}

int c[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                //freopen("output.txt", "w", stdout);
                off = true;
        #endif
        ios_base::sync_with_stdio(0);

        if(off){
                n = 1000;
                m = 10000;
        } else{
                cin >> n >> m;
        }

        int my = 0;

        again:
        my = 0;
        for(int i = 0; i < n; i++){
                c[i] = 0;
        }

        for(int i = 1; i <= m; i++){
                auto s = get();

                vector < pair < int, int > > v;
                for(int i = 0; i < n; i++){
                        if(c[i] * 1.1 + 10 > my){
                                continue;
                        }
                        v.push_back({c[i], i});
                }
                sort(v.begin(), v.end());

                char c = rng() % 2 + '0';
                if(!v.empty()){
                        int g = min((int)v.size(), n);
                        int id = abs((int)rng()) % g;
                        c = s[v[id].se];
                }

                if(rng() % 3 == 0){
                        //c = rng() % 2 + '0';
                }

                char y;

                if(off){
                        y = '1';
                        int gg = 2;
                        if(i / gg % 2){
                                y = '0';
                        }
                } else{
                        cout << c << endl;
                        cin >> y;
                }
                my += (c != y);
                for(int i = 0; i < n; i++){
                        ::c[i] += (s[i] != y);
                }
        }
        if(!off){
                exit(0);
        }
        int best = c[0];
        for(int i = 1; i < n; i++){
                best = min(best, c[i]);
        }
        cout << best << " " << my << endl;

        if((double)my > (double)1.3 * best + 100){
                cout << "SUKA" << "\n";
                exit(0);
        }
        cout << "OK" << endl;
        goto again;
}