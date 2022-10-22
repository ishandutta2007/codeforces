#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200000;
int n;
#define Maxn 200010
int a[Maxn],sum[Maxn];
bool vis[Maxn];
int p[Maxn];
void init(){
	for(int i=2;i<=N;++i){
		if(!vis[i])p[++p[0]]=i;
		for(int j=1;j<=p[0]&&1ll*i*p[j]<=N;++j){
		    vis[i*p[j]]=true;
			if(i%p[j]==0)break;	
		} 
	}
}
int main(){
	scanf("%d",&n);
	int x;
	while(n--){
		scanf("%d",&x);
		a[x]++;
	}
	for(int i=1;i<=N;++i){
		for(int j=i;j<=N;j+=i)sum[i]+=a[j];
	}
	init();
	long long ans=1;
	for(int i=2;i<=N;++i)
	    if(!vis[i]){
			int t=1,at=sum[1]-sum[i];
			while(at<=1){
				t*=i;
				ans*=i;
				at+=sum[t];
				if(1ll*t*i<=N)at-=sum[t*i];
			} 
	    }
	printf("%lld\n",ans);
	return 0;
}