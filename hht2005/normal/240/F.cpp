#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
char s[N];
struct node {
	int sum[N],tag[N];
	void push_up(int p) {
		sum[p]=sum[p<<1]+sum[p<<1|1];
	}
	void make_tag(int p,int c,int len) {
		tag[p]=c;
		sum[p]=c*len;
	}
	void push_down(int p,int len) {
		if(tag[p]!=-1) {
			make_tag(p<<1,tag[p],len-len/2);
			make_tag(p<<1|1,tag[p],len/2);
			tag[p]=-1;
		}
	}
	void mdf_cover(int p,int l,int r,int x,int y,int v) {
		if(x>y)return;
		if(x<=l&&r<=y)return make_tag(p,v,r-l+1);
		push_down(p,r-l+1);
		int mid=(l+r)>>1;
		if(x<=mid)mdf_cover(p<<1,l,mid,x,y,v);
		if(y>mid)mdf_cover(p<<1|1,mid+1,r,x,y,v);
		push_up(p);
	}
	int qry(int p,int l,int r,int x,int y) {
		if(x<=l&&r<=y)return sum[p];
		push_down(p,r-l+1);
		int mid=(l+r)>>1,ans=0;
		if(x<=mid)ans+=qry(p<<1,l,mid,x,y);
		if(y>mid)ans+=qry(p<<1|1,mid+1,r,x,y);
		return ans;
	}
	void build(int p,int l,int r,char ch) {
		tag[p]=-1;
		if(l==r) {
			sum[p]=ch==s[l];
			return;
		}
		int mid=(l+r)>>1;
		build(p<<1,l,mid,ch);
		build(p<<1|1,mid+1,r,ch);
		push_up(p);
	}
	void print(int p,int l,int r,char ch) {
		if(!sum[p])return;
		if(l==r) {
			s[l]=ch;
			return;
		}
		push_down(p,r-l+1);
		int mid=(l+r)>>1;
		print(p<<1,l,mid,ch);
		print(p<<1|1,mid+1,r,ch);
	}
}S[26];
int t[26];
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,l,r;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=0;i<26;i++)
		S[i].build(1,1,n,i+'a');
	while(m--) {
		scanf("%d%d",&l,&r);
		int f=0;
		for(int i=0;i<26;i++)
			f+=(t[i]=S[i].qry(1,1,n,l,r))&1;
		if(f<=1) {
			for(int i=0,sum=0;i<26;i++) {
				if(!t[i])continue;
				S[i].mdf_cover(1,1,n,l,r,0);
				S[i].mdf_cover(1,1,n,l+sum,l+sum+t[i]/2-1,1);
				S[i].mdf_cover(1,1,n,r-sum-t[i]/2+1,r-sum,1);
				sum+=t[i]/2;
				if(t[i]&1)S[i].mdf_cover(1,1,n,(l+r)/2,(l+r)/2,1);
			}
		}
	}
	memset(s,'.',sizeof(s));
	s[n+1]=0;
	for(int i=0;i<26;i++)
		S[i].print(1,1,n,i+'a');
	printf("%s\n",s+1);
	return 0;
}