#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1010;
ll a[N],Ans[20*N][2];
bool bk[N][N],bz[N];int du[N];

map<ll,int> B;
bool cmp(ll n1,ll n2) {return (n1>n2);}

int main()
{
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),B[a[i]]++;
	
	sort(a+1,a+n+1,cmp);
	
	int tot=0;
	for(int i=1;i<=n;i++){
		bool pd=false;
		for(int j=n;j>=i;j--){
			if(a[i]!=a[j]&&a[i]%a[j]==0&&2*a[i]+a[j]<=m){
				du[i]++;
				bk[i][j]=true;
			}
		}
	}
	
	memset(bz,true,sizeof(bz));
	for(int i=1;i<=n;i++)
		if(3*a[i]<=m) bz[i]=false;
	for(int i=n;i>=1;i--){
		int Min=1e9,Min1=-1;
		for(int j=i;j>=1;j--)
			if(bk[j][i]&&bz[j]){
				if(Min>du[j])
					Min=du[j],Min1=j;
			}
		if(Min!=1e9){
			bz[Min1]=false;
			Ans[++tot][0]=2*a[Min1]+a[i];Ans[tot][1]=a[Min1]+a[i];
			for(int j=i;j>=1;j--)
				if(bk[j][i]&&bz[j]) du[j]--;
			B[a[Min1]]--;B[a[i]]--;
		}
	}
	
	for(int i=1;i<=n;i++)
		if(B[a[i]]){
			B[a[i]]--;
			Ans[++tot][0]=a[i]*2;
			Ans[tot][1]=a[i]*3;
			if(a[i]*3>m){
				printf("-1\n");
				return 0;
			}
		}
		
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%lld %lld\n",Ans[i][0],Ans[i][1]);
	
	return 0;
}