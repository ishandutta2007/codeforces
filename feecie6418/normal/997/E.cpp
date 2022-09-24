#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,st[120005],top,st2[120005],top2,a[120005],tagmi[480005],tag[480005],K,q;
ll ans[120005];
struct P {
	int mi,micnt;
	ll ans;
}t[480005];
struct Query{
	int l,id;
};
vector<Query> w[120005];
P operator +(P a,P b){
	return {min(a.mi,b.mi),a.micnt*(a.mi<=b.mi)+b.micnt*(b.mi<=a.mi),a.ans+b.ans};
}
void Build(int p,int l,int r){
	tag[p]=tagmi[p]=0;
	if(l==r)return t[p]={0,1,0},void();
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r),t[p]=t[p*2]+t[p*2+1];
}
void Tagmi(int p,int z){
	t[p].ans+=t[p].micnt*z,tagmi[p]+=z;
}
void Tag(int p,int z){
	t[p].mi+=z,tag[p]+=z;
}
void Pushdown(int p){
	if(tag[p])Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]=0;
	if(tagmi[p]){
		if(t[p*2].mi==t[p].mi)Tagmi(p*2,tagmi[p]);
		if(t[p*2+1].mi==t[p].mi)Tagmi(p*2+1,tagmi[p]);
		tagmi[p]=0;
	}
}
void U(int p,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y)return Tag(p,z);
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)U(p*2,l,mid,x,y,z);
	if(mid<y)U(p*2+1,mid+1,r,x,y,z);
	t[p]=t[p*2]+t[p*2+1];
}
P Q(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y)return t[p];
	Pushdown(p);
	int mid=(l+r)/2;
	if(x>mid)return Q(p*2+1,mid+1,r,x,y);
	if(y<=mid)return Q(p*2,l,mid,x,y);
	return Q(p*2,l,mid,x,y)+Q(p*2+1,mid+1,r,x,y);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&q),Build(1,1,n),st[top=0]=st2[top2=0]=0;
	for(int i=1,x,y;i<=q;i++)scanf("%d%d",&x,&y),w[y].push_back({x,i});
	for(int i=1;i<=n;i++){
		while(top&&a[st[top]]<a[i])U(1,1,n,st[top-1]+1,st[top],-a[st[top]]),top--;//st:
		while(top2&&a[st2[top2]]>a[i])U(1,1,n,st2[top2-1]+1,st2[top2],a[st2[top2]]),top2--;//st2:
		U(1,1,n,st[top]+1,i,a[i]),U(1,1,n,st2[top2]+1,i,-a[i]),U(1,1,n,1,i,-1),Tagmi(1,1);
		st[++top]=i,st2[++top2]=i;
		for(Query j:w[i])ans[j.id]=Q(1,1,n,j.l,i).ans;
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}