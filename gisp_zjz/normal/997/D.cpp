#include<bits/stdc++.h>
#define maxn 4005
#define M 998244353

using namespace std;
typedef long long ll;
const ll NM=1ll*M*M*6;
int n,m,k,a[2][maxn],c[100][100];
ll s[75],t[75],ans,p,q;
int px[maxn],qx[maxn],py[maxn],qy[maxn];
bool f,g;

void add1(int &x,int y){x+=y; if (x>=M) x-=M;}
void add2(ll &x,ll y){x+=y; if (x>=NM) x-=NM;}

int main(){
    cin >> n >> m >> k;
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        px[i]=u; py[i]=v;
    }
    for (int i=1;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        qx[i]=u; qy[i]=v;
    }
    if (k&1) {cout << 0 << endl; return 0;}
    c[0][0]=1;
    for (int i=1;i<=k;i++) {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
    }
    for (int i=1;i<=n;i++){
        memset(a,0,sizeof(a));
        a[0][i]=1; s[0]++;
        for (int j=1;j<=k/2;j++){
            g=j&1; f=!g;
            for (int u=1;u<n;u++){
                add1(a[g][py[u]],a[f][px[u]]);
                add1(a[g][px[u]],a[f][py[u]]);
            }
            for (int u=1;u<=n;u++) add2(s[j*2],1ll*a[g][u]*a[g][u]),a[f][u]=0;
        }
    }
    for (int i=1;i<=m;i++){
        memset(a,0,sizeof(a));
        a[0][i]=1; t[0]++;
        for (int j=1;j<=k/2;j++){
            g=j&1; f=!g;
            for (int u=1;u<m;u++){
                add1(a[g][qy[u]],a[f][qx[u]]);
                add1(a[g][qx[u]],a[f][qy[u]]);
            }
            for (int u=1;u<=m;u++) add2(t[j*2],1ll*a[g][u]*a[g][u]),a[f][u]=0;
        }
    }
    for (int o=0;o<=k;o+=2) s[o]%=M,t[o]%=M;
    for (int o=0;o<=k;o+=2) (ans+=c[k][o]*s[o]%M*t[k-o])%=M;
    cout << ans << endl;
}