#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

struct po {
    int x, y, z, id;
    po(int x, int y, int z, int id) : x(x), y(y), z(z), id(id) {}
};
vector<po> p;

ll n, ja[MN];
map<int, vector<int>> xx;
map<pair<int, int>, vector<int>> xy;
vector<pair<int, int>> ans;

bool cmpX(int a, int b) {
    return p[a].x < p[b].x;
}

bool cmpY(int a, int b) {
    return p[a].y < p[b].y;
}

bool cmpZ(int a, int b) {
    return p[a].z < p[b].z;
}

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        p.emplace_back(x, y, z, i);
        xx[x].push_back(i);
        xy[{x, y}].push_back(i);
    }

    for(auto &tt : xy) {
        vector<int> &v = tt.second;
        sort(v.begin(), v.end(), cmpZ);
        for(int i = 0; i + 1 < v.size(); i += 2) {
            ans.emplace_back(v[i], v[i+1]);
            ja[v[i]]   = 1;
            ja[v[i+1]] = 1;
        }
    }

    for(auto &tt : xx) {
        vector<int> v;
        for(int id : tt.second)
            if(!ja[id]) v.push_back(id);

        sort(v.begin(), v.end(), cmpY);
        for(int i = 0; i + 1 < v.size(); i += 2) {
            ans.emplace_back(v[i], v[i+1]);
            ja[v[i]]   = 1;
            ja[v[i+1]] = 1;
        }
    }

    vector<int> v;
    for(auto pp : p)
        if(!ja[pp.id]) v.push_back(pp.id);

    sort(v.begin(), v.end(), cmpX);
    for(int i = 0; i + 1 < v.size(); i += 2) {
        ans.emplace_back(v[i], v[i+1]);
        ja[v[i]]   = 1;
        ja[v[i+1]] = 1;
    }

    for(auto tt : ans) {
        printf("%d %d\n", tt.first + 1, tt.second + 1);
    }
    return 0;
}