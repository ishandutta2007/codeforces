#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
#define maxn 100010
char ch[maxn];
int seq[maxn];
struct Segment_Tree{
	int sum[maxn*4],tag[maxn*4];
	bool set[maxn*4];
	int id;
	void push_down(int k,int l,int r){
		int mid=(l+r)>>1;
		if(set[k]){
			sum[k<<1]=sum[k<<1|1]=0;
			tag[k<<1]=tag[k<<1|1]=0;
			set[k<<1]=set[k<<1|1]=true;
			set[k]=false;
		}
		sum[k<<1]+=tag[k]*(mid-l+1);
		sum[k<<1|1]+=tag[k]*(r-mid);
		tag[k<<1]+=tag[k];
		tag[k<<1|1]+=tag[k];
		tag[k]=0;
	}
	void push_up(int k){sum[k]=sum[k<<1]+sum[k<<1|1];}
	void Add(int k,int l,int r,int L,int R){
		if(l==L&&r==R){tag[k]++;sum[k]+=(R-L+1);return;}
		push_down(k,l,r);
		int mid=(l+r)>>1;
		if(R<=mid)Add(k<<1,l,mid,L,R);
		else if(mid<L)Add(k<<1|1,mid+1,r,L,R);
		else{
			Add(k<<1,l,mid,L,mid);
			Add(k<<1|1,mid+1,r,mid+1,R);
		}
		push_up(k);
	}
	void Set(int k,int l,int r,int L,int R){
		if(l==L&&r==R){set[k]=true;sum[k]=0;tag[k]=0;return;}
		push_down(k,l,r);
		int mid=(l+r)>>1;
		if(R<=mid)Set(k<<1,l,mid,L,R);
		else if(mid<L)Set(k<<1|1,mid+1,r,L,R);
		else{
			Set(k<<1,l,mid,L,mid);
			Set(k<<1|1,mid+1,r,mid+1,R);
		}
		push_up(k);
	}
	int Query(int k,int l,int r,int L,int R){
		if(l==L&&r==R)return sum[k];
		push_down(k,l,r);
	    int mid=(l+r)>>1;
	    if(R<=mid)return Query(k<<1,l,mid,L,R);
	    else if(mid<L)return Query(k<<1|1,mid+1,r,L,R);
	    else return Query(k<<1,l,mid,L,mid)+Query(k<<1|1,mid+1,r,mid+1,R);
	}
	void Dfs(int k,int l,int r){
		if(l==r){
			if(sum[k])seq[l]=id;
			return;
		}
		push_down(k,l,r);
		int mid=(l+r)>>1;
		Dfs(k<<1,l,mid);
		Dfs(k<<1|1,mid+1,r);
	}
}tree[26];
void rd(int &x){x=0;char ch=getchar();while(ch<'0'||ch>'9')ch=getchar();while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}}
int main(){
	rd(n);rd(m);
	scanf("%s",ch+1);
	for(int i=0;i<26;++i)tree[i].id=i;
	for(int i=1;i<=n;++i)
	tree[ch[i]-'a'].Add(1,1,n,i,i);
	int l,r,opt;
	for(int i=1;i<=m;++i){
		rd(l);rd(r);rd(opt);
		int last=l-1;
		if(opt){
			for(int i=0;i<26;++i){
				int now=tree[i].Query(1,1,n,l,r);
				if(now){
					tree[i].Set(1,1,n,l,r);
					tree[i].Add(1,1,n,last+1,last+now);
				}
				last+=now;
			}
		}else{
			for(int i=25;i>=0;--i){
				int now=tree[i].Query(1,1,n,l,r);
				if(now){
					tree[i].Set(1,1,n,l,r);
					tree[i].Add(1,1,n,last+1,last+now);
				}
				last+=now;
			}
		}
	}
	for(int i=0;i<26;++i)tree[i].Dfs(1,1,n);
	for(int i=1;i<=n;++i)putchar('a'+seq[i]);
	return 0;
}