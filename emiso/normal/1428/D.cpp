#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

void cant() {
    puts("-1");
    exit(0);
}

int t, n, a[MN];
vector<pair<int, int>> ans;

set<int> row0, /*row1,*/ col1row2, col1row1;
vector<int> col[MN];

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        row0.insert(i);
    }

    for(int i = n-1; i >= 0; i--) {
        if(a[i] == 0) {
        } else if(a[i] == 1) {
            if(row0.empty()) cant();
            int r = *(row0.rbegin());
            row0.erase(r);
            ans.emplace_back(r, i);
            col[i].push_back(r);
            //row1.insert(r);
            col1row1.insert(i);
        } else if(a[i] == 2) {
            if(col1row1.empty()) cant();
            int c = *(col1row1.rbegin());
            col1row1.erase(c);
            int r = col[c].back();
            ans.emplace_back(r, i);
            col[i].push_back(r);
            col1row2.insert(i);
        } else if(a[i] == 3) {
            if(row0.empty()) cant();
            int r = *(row0.rbegin());
            row0.erase(r);

            if(!col1row2.empty()) {
                int c = *(col1row2.rbegin());
                col1row2.erase(c);
                ans.emplace_back(r, c);
            } else if(!col1row1.empty()) {
                int c = *(col1row1.rbegin());
                col1row1.erase(c);
                ans.emplace_back(r, c);
            } else cant();

            ans.emplace_back(r, i);
            col[i].push_back(r);
            col1row2.insert(i);
        }
    }

    for(int i = 0; i < n; i++)
        assert(col[i].size() <= 2);

    printf("%d\n", ans.size());
    for(auto tt : ans) printf("%d %d\n", tt.first+1, tt.second+1);
    return 0;
}