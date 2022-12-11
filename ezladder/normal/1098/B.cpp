#include <bits/stdc++.h>
using namespace std;
           
#define ll long long
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, m;
vector<vector<char> > a, b, c;
ll ans = 1e18;

void solve1(char c1, char c2, char c3, char c4){
    char g[2][2];
    g[0][0] = c1; g[0][1] = c2;
    g[1][0] = c3; g[1][1] = c4;
    ll now = 0;
    for (int i = 0; i < n; i++){
        int w1 = 0, w2 = 0;
        for (int j = 0; j < m; j++){
            w1 += (g[i % 2][j % 2] != a[i][j]);
            w2 += (g[i % 2][(j + 1) % 2] != a[i][j]);
        }
        if (w1 < w2){
            for (int j = 0; j < m; j++) c[i][j] = g[i % 2][j % 2];
        } else {
            for (int j = 0; j < m; j++) c[i][j] = g[i % 2][(j + 1) % 2];
        }
        now += min(w1, w2);
    }
    if (now < ans){
        ans = now;
        b = c;
    }
}

void solve2(char c1, char c2, char c3, char c4){
    char g[2][2];
    g[0][0] = c1; g[0][1] = c3;
    g[1][0] = c2; g[1][1] = c4;
    ll now = 0;
    for (int j = 0; j < m; j++){
        int w1 = 0, w2 = 0;
        for (int i = 0; i < n; i++){
            w1 += (g[i % 2][j % 2] != a[i][j]);
            w2 += (g[(i + 1) % 2][j % 2] != a[i][j]);
        }
        if (w1 < w2){
            for (int i = 0; i < n; i++) c[i][j] = g[i % 2][j % 2];
        } else {
            for (int i = 0; i < n; i++) c[i][j] = g[(i + 1) % 2][j % 2];
        }
        now += min(w1, w2);
    }
    if (now < ans){
        ans = now;
        b = c;
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    a.resize(n + 1); 
    b.resize(n + 1); 
    c.resize(n + 1);  
    for (int i = 0; i < n; i++){
        a[i].resize(m + 1);
        b[i].resize(m + 1);
        c[i].resize(m + 1);
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    vector<char> d = {'A', 'G', 'C', 'T'};
    for (int i1 = 0; i1 < d.size(); i1++)
    for (int i2 = 0; i2 < d.size(); i2++)
    for (int i3 = 0; i3 < d.size(); i3++)
    for (int i4 = 0; i4 < d.size(); i4++){
        set<int> se;
        se.insert(i1);
        se.insert(i2);
        se.insert(i3);
        se.insert(i4);
        if (se.size() == 4) solve1(d[i1], d[i2], d[i3], d[i4]), solve2(d[i1], d[i2], d[i3], d[i4]);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << b[i][j];
        }
        cout << "\n";
    }
}