#include<bits/stdc++.h>
using namespace std;
vector<int> v[500005];
int leaf=0;
int b[500005];
void dfs(int a,int last,int step){
	int child=0;
	for(vector<int>::iterator it=v[a].begin();it!=v[a].end();it++){
		if(*it!=last){
			dfs(*it,a,step+1);
			child++;
		}
	}
	if(child==0)
	{
		b[leaf]=step;
		leaf++;
	}
}
main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int last_leaf=0;
	int ans=0;
	for(vector<int>::iterator it= v[1].begin();it!=v[1].end();it++){
		dfs(*it,1,1);
		sort(b+last_leaf,b+leaf);
		map<int,int> m;
		for(int i=last_leaf+1;i!=leaf;i++){
			if(b[i]<=b[i-1])
			b[i]=b[i-1]+1;
		}
		ans=max(ans,b[leaf-1]);
		last_leaf=leaf;
	}
	printf("%d\n",ans);
	return 0;
}