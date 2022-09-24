#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int k,n,m,a[100005],M,mx[100005],mxid[100005],is[100005];
struct Oper{
	int opt,x,y,id;
	double dlt;
}b[100005],c[100005];
vector<Oper> t[100005];
int main(){
	cin>>k>>m>>n;
	for(int i=1;i<=k;i++)cin>>a[i];
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		b[i]={x,y,z,i,0};
		if(x==2)t[y].push_back({x,y,z,i,0});
		if(x==1){
			mx[y]=max(mx[y],z);
			if(mx[y]==z)mxid[y]=i;
		}
	}
	for(int i=1;i<=k;i++)if(mx[i]>a[i])t[i].push_back({1,i,mx[i]-a[i],mxid[i],0});
	for(int i=1;i<=k;i++){
		sort(t[i].begin(),t[i].end(),[](Oper x,Oper y){return x.y>y.y;});
		long long sum=a[i];
		for(Oper j:t[i])b[j.id].dlt=1.0*(sum+j.y)/sum,c[++M]=b[j.id],sum+=j.y;
	}
	for(int i=1;i<=m;i++)if(b[i].opt==3)b[i].dlt=b[i].y,c[++M]=b[i];
	sort(c+1,c+M+1,[](Oper x,Oper y){return x.dlt>y.dlt;});
	for(int i=1;i<=min(M,n);i++)is[c[i].id]=1;
	cout<<min(M,n)<<'\n';
	for(int i=1;i<=k;i++){
		sort(t[i].begin(),t[i].end(),[](Oper x,Oper y){return x.y>y.y;});
		for(Oper j:t[i])if(is[j.id]&&j.opt==1)cout<<j.id<<' ';
		for(Oper j:t[i])if(is[j.id]&&j.opt!=1)cout<<j.id<<' ';
	}
	for(int i=1;i<=m;i++)if(b[i].opt==3&&is[i])cout<<i<<' ';
	return 0;
}