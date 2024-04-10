#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
#define Maxn 100010
int a[Maxn],K;
int sum[Maxn],minv[Maxn];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&K);
		bool flag=false;
		sum[0]=0;minv[0]=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]==K)flag=true;
			if(a[i]>=K)a[i]=1;
			else a[i]=-1;
			sum[i]=sum[i-1]+a[i];
			minv[i]=min(minv[i-1],sum[i]);
		}
		if(!flag){
			puts("no");
			continue;
		}
		if(n==1){
			puts("yes");
			continue;
		}
		flag=false;
		for(int i=2;i<=n;++i)
		    if(sum[i]-minv[i-2]>0){
				flag=true;
				break;
		    }
		if(flag){
			puts("yes");
			continue;
		}else puts("no");
	}
	return 0;
}