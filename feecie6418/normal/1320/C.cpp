#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
#include<vector>
#define int long long
using namespace std;
int n,m,p;
struct Weapon{
	int atk,cost;
	bool operator <(const Weapon yyy) const {
		if(atk!=yyy.atk)return atk<yyy.atk;
		else return cost>yyy.cost;
	}
}a[200005],ra[200005];
struct Armor{
	int def,cost;
	bool operator <(const Armor yyy) const {
		if(def!=yyy.def)return def<yyy.def;
		else return cost>yyy.cost;
	}
}b[200005],rb[200005];
struct Monster{
	int atk,def,val;
	bool operator <(const Monster yyy) const {
		return def<yyy.def;
	}
}c[200005];
int st[200005],top,rn,rm,maxx[800005],tag[800005];
void Build(int p,int l,int r){
	if(l==r){
		maxx[p]=-rb[l].cost;
		return ;
	}
	int mid=(l+r)/2;
	Build(p*2,l,mid);
	Build(p*2+1,mid+1,r);
	maxx[p]=max(maxx[p*2],maxx[p*2+1]);
}
void Pushdown(int p){
	maxx[p*2]+=tag[p];
	maxx[p*2+1]+=tag[p];
	tag[p*2]+=tag[p];
	tag[p*2+1]+=tag[p];
	tag[p]=0;
}
void Modify(int p,int l,int r,int x,int y,int v){
	if(x>y)return ;
	if(x<=l&&r<=y){
		maxx[p]+=v;
		tag[p]+=v;
		return ;
	}
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Modify(p*2,l,mid,x,y,v);
	if(mid<y)Modify(p*2+1,mid+1,r,x,y,v);
	maxx[p]=max(maxx[p*2],maxx[p*2+1]);
}
int Find(int x){
	int l=1,r=rm,ans=rm+1;
	while(l<=r){
		int mid=(l+r)/2;
		if(rb[mid].def>x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	//cout<<ans<<endl;
	return ans;
}
signed main() {
	//freopen("temp.in","r",stdin);
	//freopen("temp.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&p);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i].atk,&a[i].cost);
	for(int i=1;i<=m;i++)scanf("%lld%lld",&b[i].def,&b[i].cost);
	for(int i=1;i<=p;i++)scanf("%lld%lld%lld",&c[i].def,&c[i].atk,&c[i].val);
	sort(a+1,a+n+1),sort(b+1,b+m+1),sort(c+1,c+p+1);
	for(int i=1;i<=n;i++){
		while(top&&a[st[top]].cost>a[i].cost)top--;
		st[++top]=i;
	}
	rn=top;
	for(int i=1;i<=top;i++)ra[i]=a[st[i]];
	top=0;
	for(int i=1;i<=m;i++){
		while(top&&b[st[top]].cost>b[i].cost)top--;
		st[++top]=i;
	}
	rm=top;
	for(int i=1;i<=top;i++)rb[i]=b[st[i]];
//	cout<<rn<<' '<<rm<<endl;
	memset(maxx,0xc0,sizeof(maxx));
	Build(1,1,rm);
	int ans=-0x3f3f3f3f3f3f3f3fll;
	for(int i=1,j=1;i<=rn;i++){
	//	cout<<"I:"<<i<<endl;
		while(j<=p&&c[j].def<ra[i].atk){
			Modify(1,1,rm,Find(c[j].atk),rm,c[j].val);
			j++;
		}
		ans=max(ans,maxx[1]-ra[i].cost);
	//	cout<<"J:"<<j<<endl;
	//	cout<<"A:"<<maxx[1]-ra[i].cost<<endl;
	}
	printf("%lld\n",ans);
}