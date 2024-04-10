#include<bits/stdc++.h>
using namespace std;
#define N 1005
int n,m;
int a[100];
int visit[7];
int ans=0;
int digitn=0,digitm=0;
void dfs(int nn){
	if(nn==digitn+digitm){
		int aa=0;
		for(int i=0;i<digitn;i++)
		{
			aa*=7;
			aa+=a[i];
		}
		int b=0;
		for(int i=digitn;i<nn;i++){
			b*=7;
			b+=a[i];
		}
		if(aa<n&&b<m)
		ans++;
		return;
	}
	for(int i=0;i<7;i++){
		if(!visit[i]){
			visit[i]=1;
			a[nn]=i;
			dfs(nn+1);
			visit[i]=0;
		}
	}
	
} 
int main(){
	memset(visit,0,sizeof(visit));
	memset(a,0,sizeof(a));
	scanf("%d %d",&n,&m);
	int aa=n,b=m;
	aa--,b--;
	if(aa==0)
	aa++;
	if(b==0)
	b++;
	while(aa)
	digitn++,aa/=7;
	while(b)
	digitm++,b/=7;
	dfs(0);
	printf("%d\n",ans);
}