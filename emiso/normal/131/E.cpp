#include <bits/stdc++.h>

#define MN 100010

using namespace std;

int n, m, r[MN], c[MN], ans[10];

vector<int> row[MN], col[MN], ds[2*MN], dm[2*MN];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &r[i], &c[i]);
        row[r[i]].push_back(c[i]);
        col[c[i]].push_back(r[i]);
        ds[r[i]+c[i]].push_back(c[i]);
        dm[MN+r[i]-c[i]].push_back(c[i]);
    }

    for(int i = 0; i < MN; i++) {
        sort(row[i].begin(), row[i].end());
        sort(col[i].begin(), col[i].end());
        sort(ds[i].begin(), ds[i].end());
        sort(ds[MN+i].begin(), ds[MN+i].end());
        sort(dm[i].begin(), dm[i].end());
        sort(dm[MN+i].begin(), dm[MN+i].end());
    }

    for(int i = 0; i < m; i++) {
        int q = 0;

        if(row[r[i]].size() < 3) q += (row[r[i]].size() - 1);
        else if(row[r[i]][0] == c[i] || row[r[i]].back() == c[i]) q += 1;
        else q += 2;

        if(col[c[i]].size() < 3) q += (col[c[i]].size() - 1);
        else if(col[c[i]][0] == r[i] || col[c[i]].back() == r[i]) q += 1;
        else q += 2;

        if(ds[r[i]+c[i]].size() < 3) q += (ds[r[i]+c[i]].size() - 1);
        else if(ds[r[i]+c[i]][0] == c[i] || ds[r[i]+c[i]].back() == c[i]) q += 1;
        else q += 2;

        if(dm[MN+r[i]-c[i]].size() < 3) q += (dm[MN+r[i]-c[i]].size() - 1);
        else if(dm[MN+r[i]-c[i]][0] == c[i] || dm[MN+r[i]-c[i]].back() == c[i]) q += 1;
        else q += 2;

        ans[q]++;
    }

    for(int i = 0; i <= 8; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}