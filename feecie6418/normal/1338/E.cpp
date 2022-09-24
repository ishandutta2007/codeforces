#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,oud[8005],to[8005];
char g[8005][8005],str[2005],nlast[8005];
ll ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		for(int j=1;j*4<=n;j++){
			int x=str[j]-'0';
			if(isalpha(str[j]))x=str[j]-'A'+10;
			for(int k=0;k<4;k++)if(x&(1<<k))g[i][j*4-k]=1,oud[i]++;
		}
	}
	int all=n;
	while(1){
		bool ok=0;
		for(int i=1;i<=n;i++)
			if(!nlast[i]&&oud[i]==all-1){
				all--,nlast[i]=1,ok=1;
				break;
			}
		if(!ok)break;
	}
	ans+=(614ll*n+1)*(all+n-1)*(n-all)/2;
	int sall=all*(all-1)/2,s2=0;
	ans+=sall;
	for(int i=1;i<=n;i++){
		if(nlast[i])continue;
		for(int j=1;j<=n;j++)if(g[i][j]&&(!to[i]||g[to[i]][j]))to[i]=j;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!nlast[i]&&!nlast[j]&&i!=j&&!g[i][j]&&g[to[i]][j])s2++;
		}
	}
	ans+=2*s2+3*(sall-s2);
	cout<<ans;
}