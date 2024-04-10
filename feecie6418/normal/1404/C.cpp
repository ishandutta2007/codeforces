#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],ans[300005],tag[1200005];
struct P{
	int mx,sum,len;
}t[1200005];
P operator +(P a,P b){
	return {max(a.mx,b.mx),a.sum+b.sum,a.len+b.len};
}
struct Query{
	int r,id;
};
vector<Query> q[300005];
void Build(int p,int l,int r){
	if(l==r)return t[p]={(a[l]>=0?-a[l]:-(1<<30)),0,1},void();
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	t[p]=t[p*2]+t[p*2+1];
}
void Tag(int p,int x){
	tag[p]+=x,t[p].sum+=t[p].len*x,t[p].mx+=x;
}
void Pushdown(int p){
	if(tag[p])Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]=0;
}
void Add(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y)return Tag(p,1),void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Add(p*2,l,mid,x,y);
	if(mid<y)Add(p*2+1,mid+1,r,x,y);
	t[p]=t[p*2]+t[p*2+1];
}
void Upd(int p,int l,int r,int x){
	if(l==r)return t[p]={-(1<<30),t[p].sum,1},void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Upd(p*2,l,mid,x);
	else Upd(p*2+1,mid+1,r,x);
	t[p]=t[p*2]+t[p*2+1];
}
int Que(int p,int l,int r,int x){
	if(l==r)return t[p].sum;
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)return Que(p*2,l,mid,x);
	else return Que(p*2+1,mid+1,r,x);
}
P Que2(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y)return t[p];
	Pushdown(p);
	int mid=(l+r)/2;
	if(x>mid)return Que2(p*2+1,mid+1,r,x,y);
	if(y<=mid)return Que2(p*2,l,mid,x,y);
	return Que2(p*2,l,mid,x,y)+Que2(p*2+1,mid+1,r,x,y);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=i-a[i];
	//for(int i=1;i<=n;i++)cout<<a[i]<<'\n';
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),q[1+x].push_back({n-y,i});
	Build(1,1,n);
	for(int i=n;i>=1;i--){
		while(1){
			int l=i,r=n,ans=n+1;
			while(l<=r){
				int mid=(l+r)/2;
				if(Que2(1,1,n,i,mid).mx>=0)ans=mid,r=mid-1;
				else l=mid+1;
			}
			if(ans==n+1)break;
			Add(1,1,n,ans,n);
			Upd(1,1,n,ans);
			//cout<<i<<' '<<ans<<endl;
		}
		for(Query j:q[i])ans[j.id]=Que(1,1,n,j.r);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}