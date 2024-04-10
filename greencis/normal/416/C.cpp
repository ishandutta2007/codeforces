#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
using namespace std;

int n2,n,k,r[1005],used[1005];
vector<pair<int,int> > ans;
int res;

struct entry {
    int c,p,idx;
} e[1005];

struct entry2 {
    int r,idx;
} e2[1005];

int comp_cpi(entry a, entry b) {
    return a.c == b.c ? (a.p == b.p ? a.idx < b.idx : a.p < b.p) : a.c < b.c;
}

int comp_pci(entry a, entry b) {
    return a.p == b.p ? (a.c == b.c ? a.idx < b.idx : a.c < b.c) : a.p > b.p;
}

int comp_entry2(entry2 a, entry2 b) {
    return a.r == b.r ? a.idx < b.idx : a.r < b.r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&e[i].c,&e[i].p);
        e[i].idx = i;
    }

    scanf("%d",&k);
    for (int i = 0; i < k; ++i) {
        scanf("%d",&e2[i].r);
        e2[i].idx = i;
    }
    sort(e2,e2+k,comp_entry2);
    sort(e,e+n,comp_pci);
    for (int i = 0; i < n && ans.size() < k; ++i) {
        int mni = 0;
        while (mni < k && (e2[mni].r < e[i].c || used[mni])) ++mni;
        if (mni < k) {
            res += e[i].p;
            ans.push_back(make_pair(e[i].idx+1,e2[mni].idx + 1));
            used[mni] = 1;
        }
    }

    printf("%d %d\n",ans.size(),res);
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n",ans[i].first,ans[i].second);
    }

    return 0;
}