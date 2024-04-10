#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+100,mod=998244353;
int a[N];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,K;scanf("%d%d",&n,&K);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		bool pd=true;
		for(int i=n;i>=n-K+1;i--){
			if(a[i]!=0&&a[i]!=-1) {pd=false;break;}
		}
		if(!pd){
			printf("0\n");
			continue;
		}
		int Ans=1;
		for(int i=1;i<=n-K;i++){
			if(a[i]==0) Ans=(ll)Ans*(K+1)%mod;
			else if(a[i]==-1) Ans=(ll)Ans*(K+i)%mod;
		}
		for(int i=1;i<=K;i++) Ans=(ll)Ans*i%mod;
		printf("%d\n",Ans);
	}
	
	
	return 0;
}