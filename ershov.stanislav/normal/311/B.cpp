#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

#ifdef ONLINE_JUDGE
const int maxn=111111;
#else
const int maxn=100;
#endif

int n, m, p, e[maxn], y[111][maxn], z[111], w[111];
long long x[111][maxn], f[maxn], ans;

double fnc(int j, int a, int b) {
    return ((double)x[j][b]-x[j][a]) / (f[b]-f[a]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m >> p;
    for (int sum=0, i=1; i<=n; i++) {
        int a;
        e[i]=sum;
        if (i<n) scanf("%d", &a);
        sum+=a;
    }
    for (int i=1; i<=m; i++) {
        int h, t;
        scanf("%d%d", &h, &t);
        f[i]=t-e[h];
    }
    sort(f+1, f+m+1);
    long long sum=0;
    for (int i=1; i<=m; i++) sum+=f[m]-f[i];
    for (int i=0; i<=p; i++) x[i][m]=sum, y[i][0]=m, z[i]=1, w[i]=1;
    ans=sum;
    for (int i=m-1; i>=1; i--) {
        for (int j=p; j>=2; j--) {
            int k=w[j];
            x[j][i]=x[j-1][y[j-1][k-1]]-i*(f[y[j-1][k-1]]-f[i]);
            while (k<z[j-1]&&x[j][i]>x[j-1][y[j-1][k]]-i*(f[y[j-1][k]]-f[i])) x[j][i]=x[j-1][y[j-1][k]]-i*(f[y[j-1][k]]-f[i]), k++;
            while (z[j]>=w[j+1]+1&&z[j]>=2&& !(f[y[j][z[j]-1]]-f[i]==0) &&(f[y[j][z[j]-2]]-f[y[j][z[j]-1]]==0 || fnc(j, y[j][z[j]-1], i) > fnc(j, y[j][z[j]-2], y[j][z[j]-1])) ) z[j]--;
            w[j]=k;
            y[j][z[j]++]=i;
            ans=min(ans, x[j][i]);
        }
    }
    cout << ans;
    return 0;
}