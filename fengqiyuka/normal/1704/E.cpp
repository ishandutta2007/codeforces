#include<bits/stdc++.h>
using namespace std;

const int N=1010,mod=998244353,maxn=1000;
int a[N],du[N],List[N];bool bk[N];
vector<int> B[N];

int main()
{
	
	int T;
	scanf("%d",&T);
	
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		for(int i=1;i<=n;i++) du[i];
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			B[x].push_back(y);
			du[y]++;
		}
		
		int Ans=0;
		for(int i=1;i<=maxn;i++){
			bool pd=true;
			for(int j=1;j<=n;j++)
				if(a[j]) {pd=false;break;}
			if(pd) break;
			Ans++;
			for(int j=1;j<=n;j++) bk[j]=false;
			for(int j=1;j<=n;j++)
				if(a[j]) bk[j]=true;
			for(int j=1;j<=n;j++)
				if(bk[j]){
					a[j]--;
					for(auto y:B[j]) a[y]++;
				}
		}
		
		int st=0,ed=0;
		for(int i=1;i<=n;i++)
			if(!du[i]) List[++ed]=i;
			
		while(st<ed){
			int x=List[++st];
			for(auto y:B[x]){
				a[y]=(a[y]+a[x])%mod;
				du[y]--;
				if(!du[y]) List[++ed]=y;
			}
		}
		
		printf("%d\n",(a[List[n]]+Ans)%mod);
		
		for(int i=1;i<=n;i++) B[i].clear();
	}
	
	return 0;
}