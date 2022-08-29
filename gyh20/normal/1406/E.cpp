#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
bool vis[100002];
int pri[100002],tot,n,x,sum,ans,ia;
signed main(){
	srand(19260817); 
	scanf("%lld",&n);
	for(re int i=2; i<=n; ++i) {
		if(!vis[i]) {
			pri[++tot]=i;
			if(i<=sqrt(n))
			for(re int j=i*i; j<=n; j+=i)vis[j]=1;
			}
	}
	memset(vis,0,sizeof(vis));
	re int k=sqrt(tot);sum=n;ans=1;
	for(re int i=1;i<=tot;++i){
	    if(i>=k&&ans*pri[i-k+1]>n)break;
		printf("B %lld",pri[i]);cout<<endl;
		re int num=0;
		for(re int j=pri[i];j<=n;j+=pri[i]){
			if(!vis[j]){
				++num;--sum;
				vis[j]=1;
			}
		}
		scanf("%lld",&x);
		if(x!=num){
			for(re int kk=pri[i];kk<=n;kk*=pri[i]){
					printf("A %lld",kk);cout<<endl;
					scanf("%lld",&x);
					if(x)ans*=pri[i];
					else break;
			}
		}
		if((i==tot||i%k==0)&&!ia){
			printf("A 1");cout<<endl;
			scanf("%lld",&x);
			if(x!=sum){
				for(re int j=i-k+1;j<=i;++j){
					for(re int kk=pri[j];kk<=n;kk*=pri[j]){
						printf("A %lld",kk);cout<<endl;
						scanf("%lld",&x);
						if(x)ans*=pri[j],ia=1;
						else break;
					}
					if(ia)break;
				}
			}
		}
	}
	printf("C %lld",ans);cout<<endl;
}