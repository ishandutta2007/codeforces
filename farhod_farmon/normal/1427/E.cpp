#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 100100;

using namespace std;

long long inf = (1ll << 50);
vector < char > tp;
vector < pair < long long, long long > > res;
long long bs[50];

bool can_get(long long x)
{
        for(int i = 0; i < 50; i++){
                if(x & (1ll << i)){
                        x ^= bs[i];
                }
        }
        return x == 0;
}

void add(long long x)
{
        for(int i = 0; i < 50; i++){
                if(x & (1ll << i)){
                        if(bs[i]){
                                res.push_back({x, bs[i]});
                                tp.push_back('^');
                                x ^= bs[i];
                        } else{
                                bs[i] = x;
                                return;
                        }
                }
        }
        assert(0);
}

void get(long long x)
{
        long long cur = 0;
        long long was = x;
        for(int i = 0; i < 50; i++){
                if(x & (1ll << i)){
                        x ^= bs[i];
                        res.push_back({cur, bs[i]});
                        tp.push_back('^');
                        cur ^= bs[i];
                }
        }
        assert(cur == was);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        long long x;
        cin >> x;
        res.push_back({x, x});
        tp.push_back('^');

        add(x);

        while(can_get(1) == false){
                long long x = 0;
                for(int i = 0; i < 50; i++){
                        if(rng() & 1){
                                x ^= bs[i];
                        }
                }
                long long good = -1;
                long long y = x;
                for(int i = 0; i < 50 && y < inf; i++){
                        if(can_get(y) == false){
                                good = y;
                                break;
                        }
                        y *= 2;
                }
                for(int it = 0; it < 50; it++){
                        long long k = rng() % 32173821;
                        k = abs(k) + 1;
                        if(x < inf / k && x * k < inf && can_get(x * k) == false){
                                good = x * k;
                                break;
                        }
                }
                if(good == -1){
                        continue;
                }
                get(x);
                long long k = good / x;
                long long need = 1;
                y = x;
                while(need * 2 <= k){
                        res.push_back({y, y});
                        tp.push_back('+');
                        need *= 2;
                        y *= 2;
                }
                long long cur = 0;
                for(int i = 0; i < 50; i++){
                        if(k & (1ll << i)){
                                // x * (1ll << i)
                                res.push_back({cur, x * (1ll << i)});
                                tp.push_back('+');
                                cur += x * (1ll << i);
                        }
                }
                add(good);
        }
        get(1);

        assert((int)res.size() <= 100000);

        cout << res.size() << "\n";

        //return 0;

        for(int i = 0; i < res.size(); i++){
                cout << res[i].fi << " " << tp[i] << " " << res[i].se << "\n";
        }
}