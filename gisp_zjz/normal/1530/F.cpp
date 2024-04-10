#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=31607;
int n,ans,a[25][25],b[25][25],p[25],inv[M],res;
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
void sub(int &x,int y){x-=y;if (x<0) x+=M;}
void dfs(int x,int cof){
    if (x==n){
        int w=1;
        for (int i=0;i<n;i++) w=w*(M+1-p[i])%M;
        res=(res+w*cof)%M;
        return;
    }
    for (int i=0;i<n;i++) p[i]=p[i]*b[x][i]%M;
    dfs(x+1,cof);
    for (int i=0;i<n;i++) p[i]=p[i]*inv[b[x][i]]%M,cof=cof*b[x][i]%M;
    dfs(x+1,M-cof);
}
int solve(){
    for (int i=0;i<n;i++) p[i]=1; res=0;
    dfs(0,1);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (b[i][j]==1) res=res*a[i][j]%M;
    return res;
}
int main(){
    inv[1]=1; for (int i=2;i<M;i++) inv[i]=M-(M/i)*inv[M%i]%M;
    cin >> n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
            cin >> a[i][j];
            a[i][j]=a[i][j]*inv[10000]%M;
        }
    memcpy(b,a,sizeof(b));
    add(ans,solve());
    memcpy(b,a,sizeof(b));
    for (int i=0;i<n;i++) b[i][i]=1;
    sub(ans,solve());
    memcpy(b,a,sizeof(b));
    for (int i=0;i<n;i++) b[i][n-1-i]=1;
    sub(ans,solve());
    memcpy(b,a,sizeof(b));
    for (int i=0;i<n;i++) b[i][i]=b[i][n-1-i]=1;
    add(ans,solve());
    printf("%d\n",(M+1-ans)%M);
}