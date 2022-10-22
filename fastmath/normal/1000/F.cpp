#include <bits/stdc++.h>
using namespace std;
vector<int> arr, pos, mx, rl;
vector<pair<int, int> > rmq;
vector<vector<int> > where;
int INF = -1e9;
void add(int i, int l, int r, int ind, int val){
    if (r-l==1){
        rmq[i] = {val, l};
        return;
    }
    int mid = (l+r)/2;
    if (ind < mid) add(2*i+1, l, mid, ind, val);
    else add(2*i+2, mid, r, ind, val);
    rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);
}
pair<int, int> get(int i, int l, int r, int l1, int r1){
    if (l1 >= r1) return {INF, -1};
    if (l==l1&&r==r1) return rmq[i];
    int mid = (l+r)/2;
    return max(get(2*i+1, l, mid, l1, min(r1, mid)), get(2*i+2, mid, r, max(l1, mid), r1));
}
int32_t main()
{
	//freopen("1.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, x;
    cin >> n;
    k = 1;
    map<int, int> elem;
    for (int i=0; i < n; i++){
        cin >> x;
        if (elem.count(x)) arr.push_back(elem[x]);
        else{
            rl.push_back(x);
            int sz = elem.size();
            elem[x] = sz;
            arr.push_back(sz);
        }
    }
    for (int i=0; i < 4*n; i++) rmq.push_back({INF, -1});
    for (int i=0; i < elem.size(); i++) where.push_back({});
    for (int i=0; i < n; i++) where[arr[i]].push_back(i);
    for (int i=0; i < elem.size(); i++) where[i].push_back(n);
    vector<int> indices;
    for (int i=0; i < elem.size(); i++) indices.push_back(k-1);
    for (int i=0; i < elem.size(); i++) if (where[i].size() > k) add(0, 0, n, where[i][k-1], where[i][k]-1);
    int q;
    cin >> q;
    vector<vector<pair<int, int> > > queries(n);
    for (int i=0; i < q; i++){
        int a, b;
        cin >> a >> b;
        queries[a-1].push_back({b-1, i});
    }
    vector<int> ans(q);
    for (int i=0; i < n; i++){
        for (int j=0; j < queries[i].size(); j++){
            pair<int, int> p = queries[i][j];
            pair<int, int> res = get(0, 0, n, 0, p.first+1);
            if (res.first >= p.first) ans[p.second] = arr[res.second];
            else ans[p.second] = -1;
        }
        int who = arr[i];
        indices[who]++;
        int K = indices[who];
        if (where[who].size() > K) add(0, 0, n, where[who][K-1], INF);
        if (where[who].size() > K+1) add(0, 0, n, where[who][K], where[who][K+1]-1);
    }
    for (int i=0; i < q; i++){
        if (ans[i]==-1) cout << 0 << "\n";
        else cout << rl[ans[i]] << "\n";
    }
    return 0;
}