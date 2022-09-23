#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int b[N];
int l[N];
int r[N];
int mn;
vector < int > v[N], e[N];

void upd(int l, int r)
{
        while(l <= r){
                b[l] -= 1;
                if(b[l] < b[mn]){
                        mn = l;
                }
                l += 1;
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        int q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= q; i++){
                cin >> l[i] >> r[i];
                v[r[i]].push_back(i);
                e[l[i]].push_back(i);
        }
        int res = 0, x = 0, y = 0;
        for(int i = 1; i <= n; i++){
                b[i] = a[i];
        }
        b[0] = 1e9;
        b[n + 1] = 1e9;
        mn = 0;
        for(int i = 1; i <= n; i++){
                if(b[i - 1] < b[mn]){
                        mn = i - 1;
                }
                for(int j: v[i - 1]){
                        upd(l[j], r[j]);
                }
                if(b[i] - b[mn] > res){
                        res = b[i] - b[mn];
                        x = i;
                        y = mn;
                }
        }
        for(int i = 1; i <= n; i++){
                b[i] = a[i];
        }
        mn = 0;
        for(int i = n; i >= 1; i--){
                if(b[i + 1] < b[mn]){
                        mn = i + 1;
                }
                for(int j: e[i + 1]){
                        upd(l[j], r[j]);
                }
                if(b[i] - b[mn] > res){
                        res = b[i] - b[mn];
                        x = i;
                        y = mn;
                }
        }
        cout << res << "\n";
        vector < int > gg;
        for(int i = 1; i <= q; i++){
                if(y < x && r[i] < x){
                        gg.push_back(i);
                }
                if(x < y && l[i] > x){
                        gg.push_back(i);
                }
        }
        cout << gg.size() << "\n";
        for(int x: gg){
                cout << x << " ";
        }
}