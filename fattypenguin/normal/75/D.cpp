#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <iostream>
#include <map>

using namespace std;

typedef long long int64;

int64 max(int64 a,int64 b) {return a> b?a:b;}

int64 L[55],R[55],S[55],F[55],MX[55];
int64 D[55][5120],N[55];

int main()
{
    int n,m;
    cin >> n >> m;
    for (int i = 0;i < n;++i)
    {
        cin >> N[i];
        MX[i] = 0xfffffff;
        MX[i] = -MX[i];
        for (int j = 0;j < N[i];++j)
        {
            cin >> D[i][j];
            MX[i] = max(MX[i],D[i][j]);
        }
    }
    for (int i = 0;i < n;++i)
    {
        int64 sum = 0,ml = 0,mx = 0,mmx = 0;
        for (int j = 0;j < N[i];++j)
        {
            sum += D[i][j];
            ml = max(ml+D[i][j],0);
            mx = max(mx,ml);
            mmx = max(sum,mmx);
        }
        S[i] = sum;
        L[i] = mmx;
        F[i] = mx;
        int64 mr = 0;
        mx = mmx = sum = 0;
        for (int j = N[i]-1;j >= 0;--j)
        {
            sum += D[i][j];
            mr = max(mr+D[i][j],0);
            mx = max(mx,mr);
            mmx = max(sum,mmx);
        }
        R[i] = mmx;
    }
    int64 ans = 0,r = 0,mx = -0xfffffff;
    for (int i = 0;i < m;++i)
    {
        int a;
        cin >> a;
        mx = max(MX[a-1],mx);
        ans = max(ans,max(F[a-1],r+L[a-1]));
        r = max(0,max (r+S[a-1],R[a-1]));
     //   cout << ans << " " << r << endl;
    }
    if (0 == ans && mx < 0) ans = mx;
    cout << ans << endl;
    return 0;
}