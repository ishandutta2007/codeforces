#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=2e5+10;
const int M=998244353;
int n,f[maxn],dp[maxn][2][2][2][3][3][3],kase=0;
char s[maxn];
void add(int &x,int y){
    x+=y; if (x>=M) x-=M;
}
int dfs(int m,int a,int b,int c,int x,int y,int z){
    if (m==n){
        if (x==1&&y==1&&z==1) return 1;
        return 0;
    }
    int &ret=dp[m][a][b][c][x+1][y+1][z+1];
    if (ret!=-1) return ret;
    ret=0;
    for (int u=0;u<=(f[m]|a);u++){
        int na=a|(u<f[m]);
        for (int v=0;v<=(f[m]|b);v++){
            int nb=b|(v<f[m]);
            for (int w=0;w<=(f[m]|c);w++){
                int nc=c|(w<f[m]);
                int xx=u^v,yy=u^w,zz=v^w;
                int nx=min(x*2+xx+yy-zz,1);
                int ny=min(y*2+yy+zz-xx,1);
                int nz=min(z*2+zz+xx-yy,1);
                if (nx<-1||ny<-1||nz<-1) continue;
                add(ret,dfs(m+1,na,nb,nc,nx,ny,nz));
            }
        }
    }
    return ret;
}
void solve(){
    cin >> s;
    n=strlen(s);
    for (int i=0;i<n;i++) f[i]=s[i]-'0';
    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0,0,0,0,0,0) << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; _=1;
    while (_--) solve();
}