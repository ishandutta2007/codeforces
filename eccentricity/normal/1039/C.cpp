#include<bits/stdc++.h>
#define N 1000005
using namespace std;
typedef long long LL;
LL c[N];int two[N],f[N],Q[N];
const int P=1e9+7;int n,m,k;
struct data{
	LL z;int x,y;
	int operator < (const data &b)const{
		return z<b.z;
	}
}u[N];
int get(int u){return f[u]==u?u:f[u]=get(f[u]);}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	two[0]=1;for (int i=1;i<=n;i++)
		two[i]=two[i-1]*2%P;
	for (int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		u[i].z=c[x]^c[y];
		u[i].x=x;u[i].y=y;
	}
	sort(u+1,u+m+1);
	int cnt=0,ans=0;
	for (int i=1;i<=m;){
		int j=i;
		for (;j<m&&u[j+1].z==u[i].z;++j);
		*Q=0;for (int k=i;k<=j;k++) 
			Q[++*Q]=u[k].x,Q[++*Q]=u[k].y;
		sort(Q+1,Q+*Q+1);
		*Q=unique(Q+1,Q+*Q+1)-(Q+1);
		for (int k=1;k<=*Q;k++)
			f[Q[k]]=Q[k];
		for (int k=i;k<=j;k++)
			f[get(u[k].x)]=get(u[k].y);
		int now=two[n-(*Q)];
		for (int k=1;k<=*Q;k++)
			if (get(Q[k])==Q[k]) now=now*2%P;
		ans+=now;ans%=P;
		cnt++;i=j+1;
	}
	ans+=1ll*two[n]*(((1ll<<k)-cnt)%P)%P;
	ans%=P;
	printf("%d\n",ans);
}