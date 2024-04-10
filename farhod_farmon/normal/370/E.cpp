#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int a[N];
int l[N];
int r[N];
pair < int, int > d[N][7];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(!l[a[i]]){
                        l[a[i]] = i;
                }
                r[a[i]] = i;
        }
        vector < int > b;
        vector < pair < int, int > > v;
        for(int i = 1; i < N; i++){
                if(!l[i]){
                        continue;
                } else if(r[i] - l[i] + 1 > 5){
                        cout << -1 << "\n";
                        return 0;
                }
                for(int j = l[i]; j <= r[i]; j++){
                        if(a[j] && a[j] != i){
                                cout << -1 << "\n";
                                return 0;
                        }
                        a[j] = i;
                }
                v.push_back({l[i], r[i]});
                b.push_back(i);
        }
        if(v.empty()){
                cout << n / 2 << "\n";
                for(int i = 1; i < n; i += 2){
                        cout << i / 2 + 1 << " " << i / 2 + 1 << " ";
                }
                if(n % 2){
                        cout << n / 2;
                }
                return 0;
        }
        for(int i = 0; i < v.size(); i++){
                for(int j = 0; j < 5; j++){
                        d[i][j] = {-1, -1};
                }
        }
        for(int j = 0; j < 5; j++){
                int len = v[0].se - v[0].fi + j + 1;
                if(v[0].se + j > n){
                        continue;
                }
                for(int h = 0; h < 5; h++){
                        if(len + h < 2 || len + h > 5){
                                continue;
                        }
                        if((b[0] - 1) * 2 <= v[0].fi - h - 1 && v[0].fi - h - 1 <= (b[0] - 1) * 5){
                                d[0][j] = {h, 0};
                        }
                }
        }
        for(int i = 1, l; i < v.size(); i++){
                for(int j = 0; j < 5; j++){
                        int len = v[i].se - v[i].fi + j + 1;
                        if(v[i].se + j > n){
                                continue;
                        }
                        for(int h = 0; h < 5; h++){
                                if(len + h < 2 || len + h > 5){
                                        continue;
                                }
                                for(int pre = 0; pre < 5; pre++){
                                        if(d[i - 1][pre].fi == -1){
                                                continue;
                                        }
                                        l = v[i].fi - v[i - 1].se - 1 - h - pre;
                                        if(l < 0 || (b[i] - b[i - 1] - 1) * 2 > l || l > (b[i] - b[i - 1] - 1) * 5){
                                                continue;
                                        }
                                        d[i][j] = {h, pre};
                                }
                        }
                }
        }
        int shit = -1;
        for(int i = 0; i < 5; i++){
                if(d[v.size() - 1][i].fi == -1){
                        continue;
                } else if(n - v.back().se - i != 1){
                        shit = i;
                        break;
                }
        }
        if(shit == -1){
                cout << -1 << "\n";
                return 0;
        }
        int cnt = n - v.back().se - shit;
        for(int i = v.back().se + shit + 1, g = b.back() + 1; i < n; i += 2, g += 1){
                a[i] = a[i + 1] = g;
        }
        for(int i = v.size() - 1; i >= 0; i--){
                auto p = d[i][shit];
                for(int j = v[i].fi - p.fi; j <= v[i].se + shit; j++){
                        a[j] = b[i];
                }
                int l = (i == 0 ? 0 : v[i - 1].se + p.se) + 1;
                vector < int > g;
                for(int j = (i == 0 ? 1 : b[i - 1] + 1); j < b[i]; j++){
                        g.push_back(j);
                }
                if(!g.empty()){
                        int can = (v[i].fi - p.fi - (i == 0 ? 0 : v[i - 1].se) - p.se - 1);
                        int x = can / (int)g.size(), rem = can % (int)g.size();
                        for(int j = 0; j < g.size(); j++){
                                int y = x;
                                if(rem){
                                        y += 1;
                                        rem -= 1;
                                }
                                while(y--){
                                        a[l] = g[j];
                                        l += 1;
                                }
                        }
                }
                shit = p.se;
        }
        if(!a[n]){
                assert(a[n - 1]);
                a[n] = a[n - 1];
        }
        cout << a[n] << "\n";
        for(int i = 1; i <= n; i++){
                cout << a[i] << " ";
        }
}