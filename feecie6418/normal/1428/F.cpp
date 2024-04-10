#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct T{
	ll mi,mx,se,micnt,len,sum;
}t[2000005];
ll tag[2000005],add[2000005],ans=0;
int n,m;
char a[500005];
T operator +(T a,T b){
	T ret;
	ret.mi=min(a.mi,b.mi),ret.len=a.len+b.len,ret.sum=a.sum+b.sum,ret.mx=max(a.mx,b.mx);
	if(a.mi==b.mi)ret.micnt=a.micnt+b.micnt,ret.se=min(a.se,b.se);
	else if(a.mi<b.mi)ret.micnt=a.micnt,ret.se=min(a.se,b.mi);
	else ret.micnt=b.micnt,ret.se=min(a.mi,b.se);
	return ret;
}
void Tag(int p,ll x){
	if(x<=t[p].mi)return ;
	t[p].sum+=(x-t[p].mi)*t[p].micnt,t[p].mi=x,tag[p]=x,t[p].mx=max(t[p].mx,x);
}
void Add(int p,ll x){
	add[p]+=x,t[p].mi+=x,t[p].sum+=t[p].len*x,t[p].mx+=x;
	if(t[p].se!=(1ll<<60))t[p].se+=x;
	if(~tag[p])tag[p]+=x;
}
void Pushdown(int p){
	if(add[p])Add(p*2,add[p]),Add(p*2+1,add[p]),add[p]=0;
	if(~tag[p])Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]=-1;
}
int O;
void Build(int p,int l,int r){
	tag[p]=-1;
	if(l==r)return t[p]={O,O,1ll<<60,1,1,0},void();
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	t[p]=t[p*2]+t[p*2+1];
}
void U(int p,int l,int r,int x,int y,ll z) {
	if(z<=t[p].mi)return ;
	if(x<=l&&r<=y&&t[p].mi<z&&z<t[p].se)return Tag(p,z),void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)U(p*2,l,mid,x,y,z);
	if(mid<y)U(p*2+1,mid+1,r,x,y,z);
	t[p]=t[p*2]+t[p*2+1];
}
void A(int p,int l,int r,int x,int y,ll z) {
	if(x<=l&&r<=y)return Add(p,z),void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)A(p*2,l,mid,x,y,z);
	if(mid<y)A(p*2+1,mid+1,r,x,y,z);
	t[p]=t[p*2]+t[p*2+1];
}
int main(){
	scanf("%d%s",&n,a+1),Build(1,1,n);
	for(int i=1,lst=0;i<=n;i++){
		if(a[i]=='0'){
			ans+=t[1].sum,lst=0;
			continue;
		}
		if(!lst)lst=i;
		A(1,1,n,lst,i,1);
		if(lst>1)U(1,1,n,1,lst-1,i-lst+1);
		ans+=t[1].sum;
	}
	cout<<ans;
}