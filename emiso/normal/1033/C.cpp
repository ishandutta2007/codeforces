#include <bits/stdc++.h>

#define MN 100100

using namespace std;

int n, ans, a[MN], res[MN];
vector<pair<int, int> > pos;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        pos.emplace_back(a[i], i);
    }
    sort(pos.begin(), pos.end(), greater<pair<int,int>>());

    for(pair<int,int> po : pos) {
        int p = po.second;

        res[p] = 0;
        for(int P = p + po.first; P < n; P += po.first)
            if(a[P] > po.first && res[P] == 0) res[p] = 1;
        for(int P = p - po.first; P >= 0; P -= po.first)
            if(a[P] > po.first && res[P] == 0) res[p] = 1;
    }

    for(int i = 0; i < n; i++)
        printf("%c", res[i] ? 'A' : 'B');
    puts("");
    return 0;
}