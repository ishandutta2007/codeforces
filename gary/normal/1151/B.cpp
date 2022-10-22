/*
	*#*#*#* Author GaryMr *#*#*#*
	
	long long
	
	dp
	
	 >=0
	
	dpg
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX=0x3f3f3f3f;
map<int,int> ever[505];
int ans[505],flag=0,tmpnum;int n,m,a[505][505];
void dfs(int lin)
{//cout<<tmpnum<<endl;
	if(flag) return;
	if(lin>n){
		if(tmpnum>0){
			
			flag=1;
			return;
		}
		return;
	}
	int Cpynum=tmpnum;
	for(int i=1;i<=m;i++){
		tmpnum=Cpynum;
		if(flag) return;
		if(lin==1){
			tmpnum=a[lin][i];
			if(ever[lin][tmpnum]) continue;
			ever[lin][tmpnum]=1;
			ans[lin]=i;
			
			dfs(lin+1);
		}
		else{
			tmpnum^=a[lin][i];
			if(ever[lin][tmpnum]) continue;
			ever[lin][tmpnum]=1;
			ans[lin]=i;
			
			dfs(lin+1);
		}
	}
	
}
int main(){
//	freopen("out.out","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	dfs(1);
	if(flag){
		printf("TAK\n");
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	}
	else{
		printf("NIE\n");
	}
	return 0;
}