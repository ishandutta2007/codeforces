#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

const int maxn=400111;

int n, m;
long long tree[maxn+11], tree2[maxn+11];
set<pair<int, int> > v;

long long getsum(int l, int r, int vl, int vr, int node, long long sum) {
    if (vl>r||vr<l) return 0;
    else if (l<=vl&&r>=vr) return (sum+tree[node])*(vr-vl+1)+tree2[node];
    else return getsum(l, r, vl, (vl+vr)/2, node*2, sum+tree[node])+getsum(l, r, (vl+vr)/2+1, vr, node*2+1, sum+tree[node]);
}
void add(int x, int l, int r, int vl, int vr, int node) {
    if (vl>r||vr<l) return;
    else if (l<=vl&&r>=vr) tree[node]+=x;
    else {
        add(x, l, r, vl, (vl+vr)/2, node*2);
        add(x, l, r, (vl+vr)/2+1, vr, node*2+1);
        tree2[node]=tree2[node*2]+tree2[node*2+1]+tree[node*2]*((vl+vr)/2+1-vl)+tree[node*2+1]*(vr-(vl+vr)/2);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n+1; i++) v.insert(make_pair(i, i));
    for (int i=0; i<m; i++) {
        int type=0, l=0, r=0, x=0;
        scanf("%d%d%d", &type, &l, &r);
        if (type==2) {
            printf("%I64d\n", getsum(l, r, 1, n, 1, 0));
        } else {
            scanf("%d", &x);
            bool flag=true;
            for (auto j=--v.lower_bound(make_pair(l, 1000000000)); j->first<=r;) {
                auto jj=j;
                int l1=j->first, r1=(++jj)->first-1, x1=j->second;
                v.erase(j);
                if (l1<l) v.insert(make_pair(l1, x1));
                if (flag) v.insert(make_pair(l, x)), flag=false;
                if (r1>r) v.insert(make_pair(r+1, x1));
                j=jj;
                add(abs(x-x1), max(l, l1), min(r, r1), 1, n, 1);
            }
        }
    }
    return 0;
}