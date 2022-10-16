#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d,x[1005],y[1005],fa[1005],sz[1005];
int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
int M(int x,int y){
	x=gf(x),y=gf(y);
	if(x==y)return 1;
	fa[x]=y,sz[y]+=sz[x];
	return 0;
}
int main(){
	cin>>n>>d;
	for(int i=1;i<=d;i++){
		cin>>x[i]>>y[i];
		for(int j=1;j<=n;j++)fa[j]=j,sz[j]=1;
		int cnt=0,oo=0;
		for(int j=1;j<=i;j++){
			cnt+=M(x[j],y[j]);
		}
		vector<int> v;
		for(int j=1;j<=n;j++)if(gf(j)==j)v.push_back(sz[j]);
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		for(int j=0;j<min((unsigned int)v.size(),(unsigned int)cnt+1);j++)oo+=v[j];
		cout<<oo-1<<'\n';
	}
}