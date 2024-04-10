#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const int Q = 10000011;
const int mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int l[N];
int r[N];
int t[N];
vector < int > v[N];

void upd(int x, int y)
{
        while(x < N){
                t[x] += y;
                x += x & -x;
        }
}

int get(int x)
{
        int res = 0;
        while(x > 0){
                res += t[x];
                x -= x & -x;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        vector < int > g;
        for(int i = 1; i <= n; i++){
                while(!g.empty() && a[i] > a[g.back()]){
                        g.pop_back();
                }
                if(g.empty()){
                        l[i] = 1;
                } else{
                        l[i] = g.back() + 1;
                }
                g.push_back(i);
        }
        g.clear();
        for(int i = n; i >= 1; i--){
                while(!g.empty() && a[i] > a[g.back()]){
                        g.pop_back();
                }
                if(g.empty()){
                        r[i] = n;
                } else{
                        r[i] = g.back() - 1;
                }
                g.push_back(i);
        }
        for(int i = 1; i <= n; i++){
                l[i] += a[i] - 1;
                if(l[i] <= r[i]){
                        v[l[i]].push_back(a[i]);
                        v[r[i] + 1].push_back(- a[i]);
                }
        }
        set < int > s;
        long long res = 0;
        for(int i = 1, j = 1; i <= n; i++){
                for(int x: v[i]){
                        if(x > 0){
                                upd(x, 1);
                        } else{
                                upd(-x, -1);
                        }
                }
                while(!s.empty() && s.find(a[i]) != s.end()){
                        s.erase(a[j]);
                        j += 1;
                }
                res += get(i - j + 1);
                s.insert(a[i]);
        }
        cout << res << "\n";
}