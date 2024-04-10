#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <set>

using namespace std;

long long lazy[800222], tree[800222];
int n, m, a[200222], l, r, x;

void build(int vl, int vr, int node) {
    if (vl==vr) tree[node]=a[vl];
    else {
        int mid=(vl+vr)/2;
        build(vl, mid, node*2);
        build(mid+1, vr, node*2+1);
        tree[node]=min(tree[node*2], tree[node*2+1]);
    }
}
void addtree(int vl, int vr, int node) {
    if (vl>r||vr<l) return;
    else if (vl>=l&&vr<=r) lazy[node]+=x;
    else {
        int mid=(vl+vr)/2;
        addtree(vl, mid, node*2);
        addtree(mid+1, vr, node*2+1);
        tree[node]=min(tree[node*2]+lazy[node*2], tree[node*2+1]+lazy[node*2+1]);
    }
}
long long getmin(int vl, int vr, int node) {
    if (vl>r||vr<l) return 1000000000000;
    else if (vl>=l&&vr<=r) return tree[node]+lazy[node];
    else {
        int mid=(vl+vr)/2;
        return min(getmin(vl, mid, node*2), getmin(mid+1, vr, node*2+1))+lazy[node];
    }
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    build(0, n-1, 1);
    scanf("%d\n", &m);
    char c[1000];
    for (int i=0; i<m; i++) {
        gets(c);
        int ll, rr;
        if (sscanf(c, "%d%d%d", &ll, &rr, &x)==3) {
            if (rr>=ll) l=ll, r=rr, addtree(0, n-1, 1);
            else {
                l=ll, r=n-1, addtree(0, n-1, 1);
                l=0, r=rr, addtree(0, n-1, 1);
            }
        } else {
            if (rr>=ll) l=ll, r=rr, printf("%I64d\n", getmin(0, n-1, 1));
            else {
                long long ans=0;
                l=ll, r=n-1, ans=getmin(0, n-1, 1);
                l=0, r=rr, ans=min(ans, getmin(0, n-1, 1));
                printf("%I64d\n", ans);
            }
        }
    }
    return 0;
}