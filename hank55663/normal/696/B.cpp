#include<bits/stdc++.h>
using namespace std;
vector<int> v[100005];
double ans[100005];
int size[100005];
int dfs1(int n){
	int sum=1;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		sum+=dfs1(*it);
	}
	return size[n]=sum;
}
void dfs2(int n){
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		ans[*it]=(size[n]-size[*it]+1)/2.0+ans[n];
		dfs2(*it);
	}
}
main(){
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int a;
		scanf("%d",&a);
		v[a].push_back(i);
	}
	ans[1]=1;
	dfs1(1);
	dfs2(1);
	printf("1.0"); 
	for(int i=2;i<=n;i++)
	printf(" %.1lf",ans[i]);
}