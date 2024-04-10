#include<bits/stdc++.h>
using namespace std;
#define N 300005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
vector<int>son[N],d[N];
int tg[N<<2],k,m,col[N],n,xx,mx,i,j,ps,D[N];
int find(int k,int l,int r){
	if(l==r){return l;}
	if(tg[ls])return find(rs,mid+1,r);
	else return find(ls,l,mid);
}
void add(int k,int l,int r,int x){
	if(l==r){tg[k]^=1;return ;} 
	if(x<=mid)add(ls,l,mid,x);
	else add(rs,mid+1,r,x);
	tg[k]=tg[ls]&tg[rs];
}
void dfs(int now,int fat){
	int i;
	for(i=0;i<d[now].size();++i){
		if(col[d[now][i]])add(1,1,m,col[d[now][i]]);
	}
	for(i=0;i<d[now].size();++i)
		if(!col[d[now][i]])col[d[now][i]]=find(1,1,m),add(1,1,m,col[d[now][i]]);
	for(i=0;i<d[now].size();++i){
		add(1,1,m,col[d[now][i]]);
	}
	for(i=0;i<son[now].size();++i){
		if((son[now][i])!=fat)dfs(son[now][i],now);
	}
}
int x,y;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;++i){
		cin>>D[i];
		for(j=0;j<D[i];++j)cin>>xx,d[i].push_back(xx);
		if(D[i]>mx)mx=D[i],ps=i;
	}
	for(i=1;i<n;++i){
		cin>>x>>y,son[x].push_back(y),son[y].push_back(x);
	}
	if(mx==0){
		cout<<"1\n";
		for(i=1;i<=m;++i)cout<<"1 ";return 0;
	}
	dfs(ps,0);
	cout<<mx<<"\n";
	for(i=1;i<=m;++i)cout<<max(1,col[i])<<" ";
//	for(i=1;i<=n;++i){
//		for(j=0;j<d[i].size();++j){
//			for(k=0;k<j;++k){
//				if(col[d[i][j]]==col[d[i][k]])cout<<i<<"\n";
//			}
//		}
//	}
}