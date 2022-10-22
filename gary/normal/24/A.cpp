#include<bits/stdc++.h>
using namespace std;
int a[101],b[101],cost[101],sum=0,result=0,n;
void dfs(int start,int bian){
	for(int i=1;i<=n;i++){
		if(i==bian) continue;
		if(a[i]==start){
			if(b[i]==a[1]) return;
			dfs(b[i],i);
		}
		else
		if(b[i]==start){
			result+=cost[i];
			if(a[i]==a[1]) return;
			dfs(a[i],i);
		}
	}
}
int main(){
//	freopen("ringroad.in","r",stdin);
//	freopen("ringroad.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>cost[i];
		sum+=cost[i];
	}
	dfs(b[1],1);
	result=min(result,sum-result);
	cout<<result;
}