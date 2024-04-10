#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P {
	int mi,micnt;
}t[1200005];
P operator +(P a,P b){
	return {min(a.mi,b.mi),a.micnt*(a.mi<=b.mi)+b.micnt*(b.mi<=a.mi)};
}
int n,st[300005],top,st2[300005],top2,a[300005],tag[1200005];
ll ans=0;
//st:a[i]
//st2:a[i]
//mx-mi-len=-1
void Build(int p,int l,int r){
	t[p]={0,r-l+1};
	if(l==r)return ;
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
}
void Tag(int p,int z){
	t[p].mi+=z,tag[p]+=z;
}
void Pushdown(int p){
	if(tag[p])Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]=0;
}
void U(int p,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y)return Tag(p,z);
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)U(p*2,l,mid,x,y,z);
	if(mid<y)U(p*2+1,mid+1,r,x,y,z);
	t[p]=t[p*2]+t[p*2+1];
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++)scanf("%d%d",&x,&y),a[x]=y;
	Build(1,1,n);
	for(int i=1;i<=n;i++){
		while(top&&a[st[top]]<a[i])U(1,1,n,st[top-1]+1,st[top],-a[st[top]]),top--;
		while(top2&&a[st2[top2]]>a[i])U(1,1,n,st2[top2-1]+1,st2[top2],a[st2[top2]]),top2--;
		U(1,1,n,st[top]+1,i,a[i]),U(1,1,n,st2[top2]+1,i,-a[i]),U(1,1,n,1,i,-1);
		ans+=t[1].micnt,st[++top]=i,st2[++top2]=i;
	}
	printf("%lld\n",ans);
	return 0;
}