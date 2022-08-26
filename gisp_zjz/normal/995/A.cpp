#include<bits/stdc++.h>
#define maxn 30000
#define F first
#define S second

using namespace std;
typedef pair<int,int> pi;
int a[5][100],n,k,m,x[maxn],y[maxn],z[maxn],cnt,f;
pi p,q,r,nxt[5][100],pre[5][100];

int main(){
    cin >> n >> k;
    for (int i=1;i<=4;i++) for (int j=1;j<=n;j++) cin >> a[i][j];
    if (k==2*n){
        f=0;
        for (int i=1;i<=n;i++) if (a[2][i]==a[1][i]||a[4][i]==a[3][i]) f=1;
        if (!f) {printf("-1\n");return 0;}
    }
    for (int i=1;i<n;i++) nxt[2][i]={2,i+1}; nxt[2][n]={3,n};
    for (int i=2;i<=n;i++) nxt[3][i]={3,i-1}; nxt[3][1]={2,1};
    for (int i=1;i<n;i++) pre[3][i]={3,i+1}; pre[3][n]={2,n};
    for (int i=2;i<=n;i++) pre[2][i]={2,i-1}; pre[2][1]={3,1};
    for (int i=0;i<=n*2;i++){
        for (int j=1;j<=n;j++) if (a[2][j]&&a[2][j]==a[1][j]){
            a[2][j]=0; x[cnt]=a[1][j]; y[cnt]=1; z[cnt++]=j;
        }
        for (int j=1;j<=n;j++) if (a[3][j]&&a[3][j]==a[4][j]){
            a[3][j]=0; x[cnt]=a[4][j]; y[cnt]=4; z[cnt++]=j;
        }
        for (int j=2;j<4;j++) for (int k=1;k<=n;k++) if (!a[j][k]) p.F=j,p.S=k;
        q=pre[p.F][p.S];
        for (int j=1;j<n*2;j++) {
            if (a[q.F][q.S]){
                r=nxt[q.F][q.S];
                x[cnt]=a[q.F][q.S];
                y[cnt]=r.F;
                z[cnt++]=r.S;
                a[r.F][r.S]=a[q.F][q.S];
                a[q.F][q.S]=0;
            }
            q=pre[q.F][q.S];
        }
    }
    cout << cnt << endl;
    for (int i=0;i<cnt;i++) cout << x[i] << ' ' << y[i] << ' ' << z[i] << endl;
}