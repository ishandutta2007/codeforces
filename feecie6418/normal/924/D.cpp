#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
struct frac{
	int x,y,id;
	frac(int xx,int yy,int z){
		if(yy<0)xx=-xx,yy=-yy;
		x=xx,y=yy,id=z;
	}
	frac(){x=y=id=0;}
}a[200005];
bool operator <(const frac &x,const frac &y){
	return 1ll*x.x*y.y<1ll*y.x*x.y;
}
bool operator ==(const frac &x,const frac &y){
	return !(x<y||y<x);
}
int n,W,c[200005],id[200005],x[200005],v[200005],id1[200005],id2[200005];
int p1[200005],p2[200005],tot;
void U(int x,int y){
	while(x<=n)c[x]+=y,x+=x&-x;
}
int Q(int x){
	int r=0;
	while(x)r+=c[x],x-=x&-x;
	return r;
}
ll ans=0;
int main(){
	scanf("%d%d",&n,&W);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&v[i]),a[i]=frac(v[i]-W,x[i],i);
	sort(a+1,a+n+1);
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&a[j+1]==a[j])j++;
		++tot;
		for(int k=i;k<=j;k++)id1[a[k].id]=tot,p1[++p1[0]]=a[k].id;
	}
	tot=0;
	for(int i=1;i<=n;i++)a[i]=frac(v[i]+W,x[i],i);
	sort(a+1,a+n+1);
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&a[j+1]==a[j])j++;
		++tot;
		for(int k=i;k<=j;k++)id2[a[k].id]=tot,p2[++p2[0]]=a[k].id;
	}
//	for(int i=1;i<=n;i++)cout<<id1[i]<<' '<<id2[i]<<'\n';
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&id1[p1[j+1]]==id1[p1[j]])j++;
		vector<int> tmp;
		for(int k=i;k<=j;k++)ans+=i-1-Q(id2[p1[k]]-1),tmp.push_back(id2[p1[k]]);
		for(int k=i;k<=j;k++)U(id2[p1[k]],1);
		ans+=1ll*tmp.size()*(tmp.size()-1)/2;
	}
	cout<<ans;
}