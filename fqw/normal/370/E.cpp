#include <iostream>
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; ++i)
const int N=200010;
int a[N], x[N], y[N], ans[N];
int n, m;

int dfs(int k, int l1, int l2) {
    l2=min(l2, x[k]);
    int r1=max(l1+1, y[k]), r2=l2+4;
    if(l1>l2 || r1>r2) return -1;
    int p=dfs(k+1, r1+1, r2+1)-1;
    if(p>0) {
        int q=max(l1, p-4);
        rep(i, q, p) ans[i]=k;
        return q;
    }
    return l1<=n+1 && l2>=n+1 && k>m ? n+1 : -1;
}

int main() {
    cin>>n; rep(i, 1, n) cin>>a[i];
    fill(x, x+N, n+1);
    fill(y, y+N, -1);
    m=0;
    rep(i, 1, n) if(a[i]>0) {
        x[a[i]]=min(x[a[i]], i);
        y[a[i]]=max(y[a[i]], i);
        m=max(m, a[i]);
    }
    if(dfs(1, 1, 1)>0) {
        cout<<ans[n]<<endl;
        rep(i, 1, n) cout<<ans[i]<<" "; cout<<endl;
    } else {
        cout<<"-1\n";
    }
    return 0;
}