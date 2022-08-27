#include<bits/stdc++.h>
#define maxn 250

using namespace std;
int ans,n,m,s,a[maxn][maxn],x[maxn],y[maxn],rx[maxn],ry[maxn];
bool f;

int main()
{
    scanf("%d%d",&n,&m); ans=12345678;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&a[i][j]);
    for (int i=0;i<=a[0][0];i++)
    {
        x[0]=i; y[0]=a[0][0]-i; f=true; s=0;
        for (int j=1;j<n;j++) x[j]=a[j][0]-y[0];
        for (int j=1;j<m;j++) y[j]=a[0][j]-x[0];
        for (int j=0;j<n;j++) f&=(x[j]>=0),s+=x[j];
        for (int j=0;j<m;j++) f&=(y[j]>=0),s+=y[j];
        for (int j=1;j<n;j++) for (int k=1;k<m;k++) f&=(x[j]+y[k]==a[j][k]);
        if (f&&s<ans){
            ans=s;
            for (int j=0;j<n;j++) rx[j]=x[j];
            for (int j=0;j<m;j++) ry[j]=y[j];
        }
    }
    if (ans==12345678) cout << -1 << endl;
    else {
        cout << ans << endl;
        for (int i=0;i<n;i++)
            for (int j=0;j<rx[i];j++)
                cout << "row " << i+1 << endl;
        for (int i=0;i<m;i++)
            for (int j=0;j<ry[i];j++)
                cout << "col " << i+1 << endl;
    }
    return 0;
}