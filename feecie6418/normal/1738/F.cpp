#include<bits/stdc++.h>
using namespace std;
int d[1005],done[1005],pl[1005],fa[1005],n,sz[1005],sumd[1005];
int Q(int x){
	cout<<"? "<<x<<endl;
	int res;
	cin>>res;
	return res;
}
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void Merge(int x,int y){
	x=gf(x),y=gf(y);
	if(x==y)return ;
	fa[x]=y,sz[y]+=sz[x],sumd[y]+=sumd[x];
}
bool check(int x){
	x=gf(x);
	return sz[x]*sz[x]>=sumd[x];
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>d[i],pl[i]=i,fa[i]=i,sz[i]=1,sumd[i]=d[i];
	sort(pl+1,pl+n+1,[](int x,int y){return d[x]>d[y];});
	while(1){
		bool ok=1;
		for(int i=1;i<=n;i++){
			int x=pl[i];
			if(check(x))continue;
			ok=0;
			while(!check(x))Merge(x,Q(x));
		}
		if(ok)break;
	}
	cout<<"! ";
	for(int i=1;i<=n;i++)cout<<gf(i)<<' ';
	cout<<endl;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}