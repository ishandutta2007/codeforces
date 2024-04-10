#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+100;
const int M=1000000007;
typedef array<int,41> A;
struct hasher {
    size_t operator()(const A& p) const {
        size_t result = 0;
        for (int i=1;i<=40;i++) result = result * 19260817 + p[i];
        return result;
    }
};
bool vis[50];
int f[50],n,mx,F[50][50],G[50][50],p[50],nf[50],inv[50];
int ways[50][50][50];
unordered_map<A,int,hasher> dp[41][41][41];
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
int C(int x,int y){
	if (y<0||y>x) return 0;
	return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}
void init(){
	inv[1]=1; for (int i=2;i<=n;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
	f[0]=nf[0]=1; for (int i=1;i<=n;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
	F[0][0]=f[n-1];
	for (int i=0;i<=n-1;i++)
	for (int j=1;j+i<=n-1;j++){
        F[i][j]=0;
        for (int x=0;x<=i;x++)
			for (int y=0;y<=j;y++){
				add(F[i][j],1ll*C(i,x)*C(j,y)%M*f[n-1-x-y]%M*f[x+y]%M);
				if (!y) add(G[i][j],1ll*C(i,x)*C(j,y)%M*f[n-1-x-y]%M*f[x+y]%M);
			}
	}
	for (int i=0;i<=n-1;i++)
	for (int j=0;j+i<=n-1;j++){
		int x=1,y=1;
		for (int k=1;k<=n;k++){
			x=1ll*x*F[i][j]%M;
			y=1ll*y*G[i][j]%M;
			ways[i][j][k]=(x-y+M)%M;
		}
	}
}
int solve(int lasttot,int tot,int block,A a){
    if (dp[lasttot][tot][block].find(a)!=dp[lasttot][tot][block].end()){
		return dp[lasttot][tot][block][a];
    }
    int ret=0,sum=n;
    for (int i=1;i<=mx;i++) sum-=a[i]*i;
    if (sum==n) return dp[lasttot][tot][block][a]=nf[block];
	A tmp=a;
    for (int i=1;i<=mx;i++) {
		if (a[i]){
			tmp[i]--;
            add(ret,1ll*ways[sum-tot-lasttot][lasttot][i]*a[i]%M*solve(lasttot,tot+i,block+1,tmp)%M);
            if (block) add(ret,1ll*ways[sum-tot][tot][i]*a[i]%M*nf[block]%M*solve(tot,i,1,tmp)%M);
			tmp[i]++;
		}
    }
    return dp[lasttot][tot][block][a]=ret;
}
int main(){
	scanf("%d",&n);
	init();
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	A a;
	for (int i=0;i<=40;i++) a[i]=0;
	for (int i=1;i<=n;i++) if (!vis[i]){
		int w=0,tmp=i;
		while (!vis[tmp]){
			w++;
			vis[tmp]=1;
			tmp=p[tmp];
		}
		a[w]++;
		mx=max(mx,w);
	}
	printf("%d\n",solve(0,0,0,a));
	return 0;
}