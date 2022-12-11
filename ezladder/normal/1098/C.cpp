#include <bits/stdc++.h>
using namespace std;
           
#define ll long long
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
ll s;

int p[100007];
int h[100007];
vector<pair<int, int> > d[100007];

bool can(int val){
    ll now = n * (ll)(n + 1) / 2;
    for (int i = 2; i <= n; i++) p[i] = i - 1;
    if (val == 1) return s == now;
    h[1] = 1;
    for (int i = 1; i <= n + 1; i++) d[i].clear();
    int hh = 0;
    for (int i = n; ; i--){
        if (d[hh].size() == 0){
            hh++;
            d[hh].pb(mp(hh, val - 1));
        }  
        if (i == hh + 1 || i == hh) break;
        if (now - (i - hh - 1) >= s){
            now -= i - hh - 1;
            p[i] = d[hh].back().x;
            d[hh + 1].pb(mp(i, val));
            d[hh].back().y--;
            if (d[hh].back().y == 0) d[hh].pop_back();
            if (now == s) break;
        } else {
            p[i] = i - (now - s) - 1;
            now = s;
            break;
        }
    }
    return now == s;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    if (s < 2 * n - 1 || s > n * (ll)(n + 1) / 2) cout << "No\n", exit(0);
    cout << "Yes\n";
    int vl = 0, vr = n;
    while(vl + 1 < vr){
        int vm = (vl + vr) >> 1;
        if (can(vm))
            vr = vm;
        else
            vl = vm;
    }
    can(vr);
    for (int i = 2; i <= n; i++) cout << p[i] << ' ';
}