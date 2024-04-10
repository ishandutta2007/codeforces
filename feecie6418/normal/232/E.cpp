#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bitset<505> f[505][505],g[505][505];
int n,m,q,ans[600005];
char a[505][505];
struct Query{
	int x1,y1,x2,y2,id;
};
void Solve(vector<Query> vec,int l,int r){
	if(!vec.size()||l>r)return ;
	int mid=(l+r)/2;
	for(int i=m;i;i--){
		f[mid][i].reset();
		if(a[mid][i]=='.')f[mid][i][i]=1,f[mid][i]|=f[mid][i+1];
	}
	for(int i=mid-1;i>=l;i--){
		for(int j=m;j;j--)if(a[i][j]=='.')f[i][j]=(f[i][j+1]|f[i+1][j]);
	}
	for(int i=1;i<=m;i++){
		g[mid][i].reset();
		if(a[mid][i]=='.')g[mid][i][i]=1,g[mid][i]|=g[mid][i-1];
	}
	for(int i=mid+1;i<=r;i++){
		for(int j=1;j<=m;j++)if(a[i][j]=='.')g[i][j]=(g[i][j-1]|g[i-1][j]);
	}
	vector<Query> ql,qr;
	for(auto i:vec){
		if(i.x2<mid)ql.push_back(i);
		else if(i.x1>mid)qr.push_back(i);
		else ans[i.id]=(g[i.x2][i.y2]&f[i.x1][i.y1]).any();
	}
	Solve(ql,l,mid-1),Solve(qr,mid+1,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	scanf("%d",&q);
	vector<Query> v;
	for(int i=1,x1,y1,x2,y2;i<=q;i++)scanf("%d%d%d%d",&x1,&y1,&x2,&y2),v.push_back({x1,y1,x2,y2,i});
	Solve(v,1,n);
	for(int i=1;i<=q;i++)cout<<(ans[i]?"Yes":"No")<<'\n';
}