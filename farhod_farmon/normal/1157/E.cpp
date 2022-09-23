#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        set < pair < int, int > > s;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                s.insert({x, i});
        }

        for(int i = 1; i <= n; i++){
                int best = (a[i] + s.begin()->fi) % n;
                pair < int, int > y = *s.begin();

                auto p = s.lower_bound({n - a[i], 0});
                if(p != s.end()){
                        int gg = (a[i] + p->fi) % n;
                        if(gg < best){
                                best = gg;
                                y = *p;
                        }
                }

                cout << best << " ";
                s.erase(y);
        }
}