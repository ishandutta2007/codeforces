#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int len[maxn<<2];
struct node{
	int f[maxn<<2],sum[maxn<<2];
	inline void tag(int p,int c) {
		f[p]=c;
		sum[p]=len[p]*c;
	}
	inline void pushdown(int p) {
		if(~f[p]) {
			tag(p<<1,f[p]);
			tag(p<<1|1,f[p]);
			f[p]=-1;
		}
	}
	int ask(int p,int l,int r,int x,int y) {
		if(x<=l&&r<=y)return sum[p];
		pushdown(p);
		int mid=(l+r)>>1,ans=0;
		if(x<=mid)ans+=ask(p<<1,l,mid,x,y);
		if(y>mid)ans+=ask(p<<1|1,mid+1,r,x,y);
		return ans;
	}
	void cover(int p,int l,int r,int x,int y,int c) {
		if(x>y)return;
		if(x<=l&&r<=y)return tag(p,c);
		pushdown(p);
		int mid=(l+r)>>1;
		if(x<=mid)cover(p<<1,l,mid,x,y,c);
		if(y>mid)cover(p<<1|1,mid+1,r,x,y,c);
		sum[p]=sum[p<<1]+sum[p<<1|1];
	}
}T[26];
char s[maxn];
void init(int p,int l,int r) {
	len[p]=r-l+1;
	if(l==r) {
		T[s[l]-'a'].sum[p]=1;
		return;
	}
	int mid=(l+r)>>1;
	init(p<<1,l,mid);
	init(p<<1|1,mid+1,r);
	for(int i=0;i<26;i++) {
		T[i].sum[p]=T[i].sum[p<<1]+T[i].sum[p<<1|1];
		T[i].f[p]=-1;
	}
}
void print(int p,int l,int r) {
	if(l==r) {
		for(int i=0;i<26;i++)
			if(T[i].sum[p])putchar(i+'a');
		return;
	}
	for(int i=0;i<26;i++)
		T[i].pushdown(p);
	int mid=(l+r)>>1;
	print(p<<1,l,mid);
	print(p<<1|1,mid+1,r);
}
int cnt[26];
int main() {
	int n,q,l,r,k;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	init(1,1,n);
	while(q--) {
		scanf("%d%d%d",&l,&r,&k);
		for(int i=0;i<26;i++)
			cnt[i]=T[i].ask(1,1,n,l,r);
		int sum=l-1;
		if(k) {
			for(int i=0;i<26;i++) {
				T[i].cover(1,1,n,l,r,0);
				T[i].cover(1,1,n,sum+1,sum+cnt[i],1);
				sum+=cnt[i];
			}
		}
		else {
			for(int i=25;i>=0;i--) {
				T[i].cover(1,1,n,l,r,0);
				T[i].cover(1,1,n,sum+1,sum+cnt[i],1);
				sum+=cnt[i];
			}
		}
	}
	print(1,1,n);
	putchar('\n');
	return 0;
}