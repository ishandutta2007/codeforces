#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
int a[1005][1005],n,m,k,pre[1005][1005],p[100005];
int ffind(int x,int y){
    if (pre[x][y]==y) return y;
    return pre[x][y]=ffind(x,pre[x][y]);
}
int main(){
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin >> a[i][j];
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n+1;j++) pre[i][j]=j;
        for (int j=1;j<=n;j++) if (a[j][i]==2) pre[i][j]=j+1;
    }
    for (int i=1;i<=k;i++) cin >> p[i];
    for (int i=1;i<=k;i++){
        int c=p[i],r=1;
        while (r<=n){
            //cout<<c<<' '<<r<<' '<<ffind(c,r)<<endl;
            r=ffind(c,r);
            if (r==n+1) break;
            pre[c][r]=ffind(c,r+1);
            if (a[r][c]==1) ++c; else --c;
        }
        printf("%d ",c);
    }
    puts("");
    return 0;
}