#include<bits/stdc++.h>
using namespace std;
int n,a[300005],ans[300005]; 
vector<int> pos[300005];
int main(){
	int t;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			pos[a[i]].push_back(i);
			ans[i]=1e9;
		}
		for(int i=1;i<=n;i++){
			if(!pos[i].size())continue;
			int j=pos[i][0];
			pos[i].push_back(n+1);
			for(int k=1;k<pos[i].size();k++)j=max(j,pos[i][k]-pos[i][k-1]);
			ans[j]=min(ans[j],i);
		}
		for(int i=1;i<n;i++)ans[i+1]=min(ans[i+1],ans[i]);
		for(int i=1;i<=n;i++)if(ans[i]==1e9)printf("-1 ");else printf("%d ",ans[i]);
		puts("");
		for(int i=1;i<=n;i++)pos[i].clear();
	}
    return 0;
}