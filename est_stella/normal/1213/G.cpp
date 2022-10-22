#include<bits/stdc++.h>
using namespace std;

int n, m;
int p[200010];
long long s[200010];
vector<pair<int, pair<int,int> > > e;
long long ans[200020];
long long cnt = 0;

int Find(int a) {
    return p[a] = p[a] == a ? a : Find(p[a]);
}

int Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    cnt -= s[a] * (s[a]-1)/2 + s[b] * (s[b]-1)/2;

    p[b] = a;
    s[a] += s[b];

    cnt += s[a] * (s[a]-1)/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        p[i] = i;
        s[i] = 1;
    }

    for(int i=1; i<n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({w, {u, v}});
    }

    sort(e.begin(), e.end());

    int ind = 0;
    for(int i=0; i<=200010; i++) {
        while(ind < n-1 && e[ind].first == i) {
            if(Find(e[ind].second.first) != Find(e[ind].second.second)) {
                Union(e[ind].second.first, e[ind].second.second);
            }
            ind++;
        }

        ans[i] = cnt;
    }

    for(int i=0; i<m; i++) {
        int t;
        cin >> t;
        cout << ans[t] << " ";
    }
}