#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

int n, m, k, w, prevv[1000], minc[1000], used[1000], anss;
char l[1000][11][11];
pair<int, int> ans[1000];

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &w);
    for (int i=0; i<k; i++) for (int j=0; j<n; j++) scanf("%s", l[i][j]);
    for (int i=0; i<k; i++) minc[i]=m*n, prevv[i]=-1;
    ans[0]=make_pair(0, -1);
    for (int i=1, pr=0; i<k; i++) {
        used[pr]=1;
        int mininext=0;
        for (int j=0, mincnext=1000; j<k; j++) if (!used[j]) {
            int cost=0;
            for (int x=0; x<n; x++) for (int y=0; y<m; y++) if (l[pr][x][y]!=l[j][x][y]) cost+=w;
            if (minc[j]>cost) prevv[j]=pr, minc[j]=cost;
            if (minc[j]<mincnext) mincnext=minc[j], mininext=j;
        }
        pr=mininext;
        ans[i]=make_pair(pr, prevv[pr]);
        anss+=minc[pr];
    }
    printf("%d\n", anss+m*n);
    for (int i=0; i<k; i++) printf("%d %d\n", ans[i].first+1, ans[i].second+1);
    return 0;
}