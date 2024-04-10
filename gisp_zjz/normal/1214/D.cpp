#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000005;
const int E=500000000;
int n,m,ans,P1,P2;
string s[maxn];
vector <int> f[maxn],g[maxn],nf[maxn],ng[maxn];
mt19937_64 gen(time(0));
bool is_prime(int x){
    for (int j=2;j*j<=x;j++) if (x%j==0) return 0;
    return 1;
}
void add1(int &x,int y){x+=y;if (x>=P1) x-=P1;}
void add2(int &x,int y){x+=y;if (x>=P2) x-=P2;}
int main(){
    scanf("%d%d",&n,&m); ans=2;
    for (int i=0;i<n;i++) cin >> s[i];
    for (int i=0;i<n;i++) {
        f[i].resize(m);g[i].resize(m);
        nf[i].resize(m);ng[i].resize(m);
    }
    P1=gen()%E+E; while (!is_prime(P1)) ++P1;
    P2=gen()%E+E; while (!is_prime(P2)) ++P2;
    for (int i=0;i<n;i++)
    for (int j=0;j<m;j++){
        if (s[i][j]=='#'){f[i][j]=g[i][j]=0;continue;}
        f[i][j]=g[i][j]=(i==0&&j==0);
        if (i>0) add1(f[i][j],f[i-1][j]),add2(g[i][j],g[i-1][j]);
        if (j>0) add1(f[i][j],f[i][j-1]),add2(g[i][j],g[i][j-1]);
    }
    for (int i=n-1;i>=0;i--)
    for (int j=m-1;j>=0;j--){
        if (s[i][j]=='#'){nf[i][j]=ng[i][j]=0;continue;}
        nf[i][j]=ng[i][j]=(i==n-1&&j==m-1);
        if (i<n-1) add1(nf[i][j],nf[i+1][j]),add2(ng[i][j],ng[i+1][j]);
        if (j<m-1) add1(nf[i][j],nf[i][j+1]),add2(ng[i][j],ng[i][j+1]);
    }
    if (nf[0][0]==0&&ng[0][0]==0){puts("0");return 0;}
    for (int i=0;i<n;i++)
    for (int j=0;j<m;j++){
        if (i==0&&j==0) continue;
        if (i==n-1&&j==m-1) continue;
        if (1ll*f[i][j]*nf[i][j]%P1==nf[0][0]&&1ll*g[i][j]*ng[i][j]%P2==ng[0][0]){
            puts("1");return 0;
        }
    }
    puts("2");
    return 0;
}