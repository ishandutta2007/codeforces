#include<bits/stdc++.h>
using namespace std;
#define N 100010
int n,m1,m2;
vector<pair<int,int> > ans;
vector<int> A,B;
struct Union_Set{
	int f[N],m;
	inline int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
	inline void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		if(fx>fy)swap(fx,fy);
		f[fy]=fx;					
	}
	void init(int n,int m){
		for(int i=1;i<=n;++i)f[i]=i;
		for(int i=1,u,v;i<=m;++i){
			cin>>u>>v;
			Merge(u,v);
		}
	}
}S1,S2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m1>>m2;
	S1.init(n,m1);
	S2.init(n,m2);
	for(int i=1;i<=n;++i){
		if(S1.getf(i)^1&&S2.getf(i)^1){
			ans.emplace_back(1,i);
			S1.Merge(1,i);
			S2.Merge(1,i);
		}
	}
	for(int i=1;i<=n;++i){
		if(S1.getf(i)^1)A.push_back(i),S1.Merge(1,i);
		if(S2.getf(i)^1)B.push_back(i),S2.Merge(1,i);
	}
	for(int i=0;i<min(A.size(),B.size());++i){
		ans.emplace_back(A[i],B[i]);
	}
	printf("%d\n",(int)ans.size());
	for(auto [x,y]:ans){
		printf("%d %d\n",x,y);
	}
	return 0;
}