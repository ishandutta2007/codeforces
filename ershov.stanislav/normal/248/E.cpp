#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <deque>
#include <iomanip>
#include <map>
#include <cmath>

using namespace std;

int n, a[111111], q, u, v, k, b[111111];
double  x[111111][111], tmp[111], ans=0;

double c(int a, int b) {
    double r=1;
    for (int i=1; i<=b; i++) r=r*a--/i;
    return r;
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        x[i][b[i]=a[i]]=1;
        if(!a[i]) ans+=1;
    }
    cin >> q;
    for (int g=0; g<q; g++) {
        cin >> u >> v >> k;
        u--; v--;
        fill(tmp, tmp+b[u]+1, 0);
        for (int i=0; i<=a[u]&&i<=b[u]; i++) for (int j=0; j<=i&&j<=k; j++) if (k-j<=a[u]-i)
            tmp[i-j]+=x[u][i]*c(i, j)*c(a[u]-i, k-j)/c(a[u], k);
        ans+=tmp[0]-x[u][0];
        for (int i=0; i<=b[u]; i++) x[u][i]=tmp[i];
        a[u]-=k;
        a[v]+=k;
        cout << fixed << setprecision(15) << ans << endl;
    }
    return 0;
}