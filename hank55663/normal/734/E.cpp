#include<bits/stdc++.h>
using namespace std;
vector<int> v[200005];
int color[200005];
int num[2];
int ans=0;
int dfs(int n,int f){
	int nsum=0,hi=0,hi2=0;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		nsum=0;
		if(*it!=f){
			if(color[*it]!=color[n])
			nsum=1;
			int h=dfs(*it,n)+nsum;
			if(h>hi)
			{
				hi2=hi;
				hi=h;
			}
			else if(h>hi2){
				hi2=h;
			}
		} 
	}
//	printf("%d %d %d\n",n,hi,hi2);
	ans=max((hi+hi2+1)/2,ans);
	return hi;
} 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&color[i]);
	}
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	num[color[1]]++;
	dfs(1,0);
	printf("%d\n",ans);
}