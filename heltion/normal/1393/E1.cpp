#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 10;
struct{
    int m;
    int d[maxn], ds[maxn], dt[maxn];
    int nd[maxn], nds[maxn], ndt[maxn];
    void nfy(int* d, int n, int* nd){
        for(int i = 0; i < n; i += 1) nd[i] = n;
        for(int i = n - 1; i >= 0; i -= 1){
            if(i + 1 < n) nd[i] = nd[i + 1];
            if(d[i]) nd[i] = i;
        }
    }
    void init(string& s, const string& t){
        m = s.size();
        for(int i = 0; i < m; i += 1) d[i] = s[i] - t[i];
        for(int i = 0; i < m - 1; i += 1) ds[i] = s[i + 1] - t[i];
        for(int i = 0; i < m - 1; i += 1) dt[i] = s[i] - t[i + 1];
        nfy(d, m, nd);
        nfy(ds, m - 1, nds);
        nfy(dt, m - 1, ndt);
    }
    int sgn(int x){
        return x < 0 ? -1 : 1;
    }
    int res(int i, int j){
        int x = min(i, j);
        if(nd[0] < x) return sgn(d[nd[0]]);
        if(i == j){
            if(i + 1 == m) return 0;
            if(nd[i + 1] == m) return 0;
            return sgn(d[nd[i + 1]]);
        }
        if(i < j){
            if(nds[i] < j) return sgn(ds[nds[i]]);
            if(j + 1 == m) return 0;
            if(nd[j + 1] == m) return 0;
            return sgn(d[nd[j + 1]]);
        }
        if(ndt[j] < i) return sgn(dt[ndt[j]]);
        if(i + 1 == m) return 0;
        if(nd[i + 1] == m) return 0;
        return sgn(d[nd[i + 1]]);
    }
}cmp[4];
constexpr int mod = 1000000007;
void add(int& x, int y){
    x += y;
    if(x >= mod) x -= mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s = "#";
    vector<int> ds = {1};
    for(int i = 0; i < n; i += 1){
        string t;
        cin >> t;
        t.push_back('#');
        vector<int> dt(t.size());
        while(s.size() < t.size()){s.push_back('#');ds.push_back(0);}
        while(s.size() > t.size()){t.push_back('#');dt.push_back(0);}
        int m = s.size();
        cmp[0].init(s, s);
        cmp[1].init(s, t);
        cmp[2].init(t, s);
        cmp[3].init(t, t);
        vector<pair<int, int>> vp;
        for(int i = 0; i < m; i += 1){
            vp.push_back({i, 0});
            vp.push_back({i, 1});
        }
        sort(vp.begin(), vp.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2){
            int res = cmp[p1.second * 2 + p2.second].res(p1.first, p2.first);
            if(res) return res < 0;
            return p1.second < p2.second;
        });
        int sum = 0;
        for(auto [x, y] : vp){
            //cout << "(" << x << "," << y << ") ";
            if(y == 0) add(sum, ds[x]);
            else add(dt[x], sum);
        }
        //cout << "\n";
        //for(int i = 0; i < m; i += 1) cout << dt[i] << " ";
        //cout << "\n";
        swap(s, t);
        swap(ds, dt);
        while((int)s.size() >= 2 and s[s.size() - 2] == '#'){
            s.pop_back();
            ds.pop_back();
        }
    }
    int ans = 0;
    for(auto x : ds) add(ans, x);
    cout << ans;
    return 0;
}