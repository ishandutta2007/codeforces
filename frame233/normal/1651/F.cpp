#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005,NC=N*21;typedef long long ll;
int c[N],r[N],tim[N],t[N];std::vector<int> v[N];
ll sc[NC],sr[NC];int ls[NC],rs[NC],nc,rt[N];
void Update(int &rt,int pos,int C,int R,int l,int r){
	int u=++nc;ls[u]=ls[rt],rs[u]=rs[rt],sc[u]=sc[rt]+C,sr[u]=sr[rt]+R,rt=u;if(l==r)return;
	int mid=(l+r)>>1;pos<=mid?Update(ls[u],pos,C,R,l,mid):Update(rs[u],pos,C,R,mid+1,r);
}
struct node{int l,r,last,val;}st[N];int top;
int search(int L,int R,int T,int l,int r,int u,int v,ll &h){
	if(L<=l&&r<=R){
		ll cur=sc[u]+(sr[v]-sr[u])*T;
		if(h>cur){h-=cur;return -1;}
		if(l==r)return l;
		ll lft=sc[ls[u]]+(sr[ls[v]]-sr[ls[u]])*T;int mid=(l+r)>>1;
		if(h<=lft)return search(L,R,T,l,mid,ls[u],ls[v],h);
		h-=lft;return search(L,R,T,mid+1,r,rs[u],rs[v],h);
	}
	int mid=(l+r)>>1;
	if(L<=mid){
		int tmp=search(L,R,T,l,mid,ls[u],ls[v],h);
		if(tmp!=-1)return tmp;
	}
	if(R>mid)return search(L,R,T,mid+1,r,rs[u],rs[v],h);
	return -1;
}
int main(){
	int n;read(n);int POS=0;
	for(int i=1;i<=n;++i)read(c[i],r[i]),tim[i]=(c[i]+r[i]-1)/r[i],t[++POS]=tim[i];
	std::sort(t+1,t+POS+1),POS=std::unique(t+1,t+POS+1)-t-1;
	for(int i=1;i<=n;++i)v[std::lower_bound(t+1,t+POS+1,tim[i])-t].pb(i);
	for(int i=1;i<=POS;++i){rt[i]=rt[i-1];for(auto it:v[i])Update(rt[i],it,c[it],r[it],1,n);}
	for(int i=n;i>=1;--i)st[++top]={i,i,0,c[i]};
	int q,T;read(q);ll ans=0,h;
	while(q--){
		read(T,h);int p=-1;
		while(top){
			node QAQ=st[top];int l=QAQ.l,r=QAQ.r,last=QAQ.last,val=QAQ.val;
			if(val==0){
				int o=std::upper_bound(t+1,t+POS+1,T-last)-t-1,pos=search(l,r,T-last,1,n,rt[o],rt[POS],h);
				if(pos==-1)--top;
				else{
					if(pos==r)--top;else st[top].l=pos+1;
					int tmp=std::min(1LL*::r[pos]*(T-last),(ll)c[pos]);
					st[++top]={pos,pos,T,tmp-(int)h},h=0,p=pos-1;break;
				}
			}
			else{
				int tmp=std::min(1LL*::r[l]*(T-last)+val,(ll)c[l]);
				if(h-tmp<=0){st[top].last=T,st[top].val=tmp-h,p=l-1,h=0;break;}
				h-=tmp,--top;
			}
		}
		if(p==-1)p=n;
		if(p>=1)st[++top]={1,p,T,0};
		ans+=h;
	}
	printf("%lld\n",ans);
	return 0;
}