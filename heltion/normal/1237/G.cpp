#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000;
int a[maxn], p[maxn], n, k, avg;
map<int, vector<int>> mp;
void distribute(int l, int len, int need){
    if(len <= 1) return;
    if(a[l] == avg and need == 0){
        distribute((l + 1) % n, len - 1, 0);
        return;
    }
    int sum = 0, m = min(len, k);
    for(int i = 0; i < m; i += 1) sum += a[(l + i) % n];
    if(sum >= avg * (m - 1) + need){
        sum -= a[l] = avg + need;
        for(int i = 1; i < m - 1; i += 1) sum -= a[(l + i) % n] = avg;
        a[(l + m - 1) % n] = sum;
        cout << l;
        for(int i = 0; i < k; i += 1) cout << " " << a[(l + i) % n];
        cout << "\n";
        distribute((l + m - 1) % n, len - m + 1, 0);
        return;
    }
    distribute((l + m - 1) % n, len - m + 1, avg * (m - 1) + need - sum + a[(l + m - 1) % n]);
    sum = 0;
    for(int i = 0; i < m; i += 1) sum += a[(l + i) % n];
    for(int i = 1; i < m; i += 1) sum -= a[(l + i) % n] = avg;
    a[l] = sum;
    cout << l;
    for(int i = 0; i < k; i += 1) cout << " " << a[(l + i) % n];
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for(int i = 0; i < n; i += 1){
        cin >> a[i];
        avg += a[i];
    }
    avg/= n;
    for(int i = 0; i < n; i += 1){
        p[i] = (i ? p[i - 1] + a[i] : a[0]) - avg;
        mp[p[i]].push_back(i);
    }
    int ans = 1;
    vector<int> cut(1);
    for(auto& p : mp){
        auto& v = p.second;
        int c = v.size();
        v.resize(c * 2);
        for(int i = 0; i < c; i += 1) v[i + c] = v[i] + n;
        map<int, int> pos;
        vector<int[20]> next(2 * c + 1);
        fill(*next.rbegin(), *next.rbegin() + 20, 2 * c);
        for(int i = 2 * c - 1; ~i; i -= 1){
            if(pos.count((v[i] + 1) % (k - 1)))
                next[i][0] = pos[(v[i] + 1) % (k - 1)];
            else next[i][0] = 2 * c;
            for(int j = 1; j < 20; j += 1) next[i][j] = next[next[i][j - 1]][j - 1];
            pos[v[i] % (k - 1)] = i;
        }
        int pans = 0, begin = 0; 
        for(int i = 0; i < c; i += 1){
            int p = i, ppans = 0;
            for(int j = 19; ~j; j -= 1) if(next[p][j] <= i + c){
                p = next[p][j];
                ppans += 1 << j;
            }
            if(p == i + c and ppans > pans){
                pans = ppans;
                begin = i;
            }
        }
        if(pans > ans){
            ans = pans;
            cut.clear();
            for(int i = begin; i < begin + c; i = next[i][0])
                cut.push_back(v[i]);
        }
    }
    int time = 0;
    vector<pair<int, int>> interval;
    for(int i = 0; i < (int)cut.size(); i += 1){
        int l = (cut[i] + 1) % n, r = (cut[(i + 1) % cut.size()] + 1) % n;
        if(r <= l) r += n;
        interval.push_back({l, r - l});
        time += (r - l + k - 3) / (k - 1);
    }
    cout << time << "\n";
    for(auto p : interval)
        distribute(p.first, p.second, 0);
    return 0;
}