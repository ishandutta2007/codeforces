#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,K,p[300005],m,x,y,q1[300005],tot1,q2[300005],tot2;long long ans;
struct segment{
	int Min,sum,last,tag;
	void pushup(const segment&L,const segment&R){
		segment l=L,r=R;
		Min=min(l.Min,r.Min);
		sum=(l.Min==Min?l.sum:0)+(r.Min==Min?r.sum:0);
		last=(r.Min==Min?r.last:l.last);
	}
}t[1200005];
void build(int k,int l,int r){
	if(l==r){t[k].last=l;return;}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	t[k].pushup(t[k<<1],t[k<<1|1]); 
}
void Tag(int k,int x){t[k].Min+=x;t[k].tag+=x;}
void pushdown(int k){
	if(t[k].tag){
		Tag(k<<1,t[k].tag);
		Tag(k<<1|1,t[k].tag);
		t[k].tag=0;
	}
}
void change(int k,int l,int r,int L,int R,int x){
	if(L<=l&&r<=R){Tag(k,x);return;}
	int mid=l+r>>1;pushdown(k);
	if(L<=mid)change(k<<1,l,mid,L,R,x);
	if(R>mid)change(k<<1|1,mid+1,r,L,R,x);
	t[k].pushup(t[k<<1],t[k<<1|1]);
}
segment query(int k,int l,int r,int L,int R){
	if(L>R)return (segment){0,0,0,0};
	if(L<=l&&r<=R){return t[k];}
	int mid=l+r>>1;segment ans;pushdown(k);
	if(R<=mid)return query(k<<1,l,mid,L,R);
	if(L>mid)return query(k<<1|1,mid+1,r,L,R);
	ans.pushup(query(k<<1,l,mid,L,R),query(k<<1|1,mid+1,r,L,R));
	return ans;
}
int tot,L[600005],R[600005],opt[600005],pos[600005],q[600005],top,h[600005],cnt;
struct edge{int to,next;}e[600005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
void dfs(int x){
	int i,y,cnt=0;if(h[x])L[x]=n+1,R[x]=0;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;dfs(y);++cnt;
		L[x]=min(L[x],L[y]);
		R[x]=max(R[x],R[y]);
	}
	if(opt[x]){
		ans+=1ll*cnt*(cnt-1)/2;	
	}
	else{
		++ans;
	}
	
}
int main(){
	n=read();build(1,1,n);
	for(int i=1;i<=n;++i){x=read();y=read();p[x]=y;}
	for(int i=1;i<=n;++i){
		while(tot1&&p[q1[tot1]]<p[i]){change(1,1,n,q1[tot1-1]+1,q1[tot1],-p[q1[tot1]]);--tot1;}
		change(1,1,n,q1[tot1]+1,i,p[i]);q1[++tot1]=i;
		while(tot2&&p[q2[tot2]]>p[i]){change(1,1,n,q2[tot2-1]+1,q2[tot2],p[q2[tot2]]);--tot2;}
		change(1,1,n,q2[tot2]+1,i,-p[i]);q2[++tot2]=i;change(1,1,n,1,i,-1);
		L[++tot]=i;R[tot]=i;pos[i]=tot;int now=tot;
		while(1){
			segment p=query(1,1,n,1,L[now]-1);
			if(top&&p.Min==-1){
				if(L[q[top]]<p.last){
					add(q[top],now);now=q[top--];
				}
				else if(L[q[top]]==p.last){
					add(++tot,q[top--]);add(tot,now);
					opt[tot]=1;L[tot]=p.last;now=tot;
				}
				else{
					add(++tot,now);L[tot]=p.last;
					do{
						y=q[top--];add(tot,y);
					}while(L[y]!=p.last);now=tot;
				}
			}
			else{q[++top]=now;break;}
		}
	}
	dfs(q[top]);printf("%lld\n",ans);
	return 0;
}