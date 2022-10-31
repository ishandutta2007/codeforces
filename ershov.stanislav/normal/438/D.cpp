#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int maxn=100000;
struct ver {
    long long maxx, sum;
    int maxi;
};
ver tree[maxn*4];
int n, m, a[maxn+11];

void update(int num) {
    tree[num].sum=tree[2*num].sum+tree[2*num+1].sum;
    if (tree[2*num].maxx>tree[2*num+1].maxx)
        tree[num].maxx=tree[2*num].maxx, tree[num].maxi=tree[2*num].maxi;
    else tree[num].maxx=tree[2*num+1].maxx, tree[num].maxi=tree[2*num+1].maxi;
}
void build(int vl, int vr, int num) {
    if (vl==vr) {
        tree[num].sum=tree[num].maxx=a[vl];
        tree[num].maxi=vl;
    } else {
        build(vl, (vl+vr)/2, num*2);
        build((vl+vr)/2+1, vr, num*2+1);
        update(num);
    }
}
void upd(int i, int x, int vl, int vr, int num) {
    if (vl==vr&&vl==i) tree[num].sum=x, tree[num].maxx=x, tree[num].maxi=i;
    else if (vr<i||vl>i) return;
    else {
        upd(i, x, vl, (vl+vr)/2, num*2);
        upd(i, x, (vl+vr)/2+1, vr, num*2+1);
        update(num);
    }
}
long long sum(int l, int r, int vl, int vr, int num) {
    if (l<=vl&&r>=vr) return tree[num].sum;
    else if (r<vl||l>vr) return 0;
    else {
        return sum(l, r, vl, (vl+vr)/2, num*2) + sum(l, r, (vl+vr)/2+1, vr, num*2+1);
    }
}
long long getmax(int l, int r, int vl, int vr, int num, int & maxi) {
    if (l<=vl&&r>=vr) {
        maxi=tree[num].maxi;
        return tree[num].maxx;
    }
    else if (r<vl||l>vr) return -1;
    else {
        int maxii1, maxii2;
        long long a1, a2, ans;
        a1=getmax(l, r, vl, (vl+vr)/2, num*2, maxii1);
        a2=getmax(l, r, (vl+vr)/2+1, vr, num*2+1, maxii2);
        if (a1>a2) maxi=maxii1, ans=a1;
        else maxi=maxii2, ans=a2;
        return ans;
    }
}
void updmod(int mod, int l, int r, int vl, int vr, int num) {
    if (tree[num].maxx<mod) return;
    else if (vr<l||vl>r) return;
    else if (vl==vr) tree[num].sum=tree[num].sum%mod, tree[num].maxx=tree[num].sum%mod, tree[num].maxi=vl;
    else {
        updmod(mod, l, r, vl, (vl+vr)/2, num*2);
        updmod(mod, l, r, (vl+vr)/2+1, vr, num*2+1);
        update(num);
    }
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    build(0, n-1, 1);
    for (int i=0; i<m; i++) {
        int type, l, r, x, k;
        cin >> type;
        if (type==1) {
            cin >> l >> r;
            l--, r--;
            cout << sum(l, r, 0, n-1, 1) << endl;
        } else if (type==3) {
            cin >> k >> x;
            k--;
            upd(k, x, 0, n-1, 1);
        } else {
            cin >> l >> r >> x;
            l--, r--;
            updmod(x, l, r, 0, n-1, 1);
        }
    }
	return 0;
}