#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int n,m,k,opt,l,r,x,y,sum1,sum2,tot,cnt=1,t[200005],top,root[200005],lazy[200005],tmp,ls[8000005],rs[8000005],sum[8000005];
set<int>s;set<int>::iterator L,R;
int Cnt[30];
char c[100005],bl[100005];
void pushup(int k){sum[k]=sum[ls[k]]+sum[rs[k]];}
int insert(int k,int l,int r,int x){
	if(!k)k=++tot;
	if(l==r){++sum[k];return k;}
	int mid=l+r>>1;
	if(x<=mid)ls[k]=insert(ls[k],l,mid,x);
	else rs[k]=insert(rs[k],mid+1,r,x);
	pushup(k);return k;
}
int merge(int p,int q,int l,int r){
	if(!p||!q)return p+q;
	if(l==r){sum[p]+=sum[q];return p;}
	int mid=l+r>>1;
	ls[p]=merge(ls[p],ls[q],l,mid);
	rs[p]=merge(rs[p],rs[q],mid+1,r);
	pushup(p);return p;
}
int splitl(int &p,int q,int l,int r,int x){
	if(!q)q=++tot;
	if(!p||l==r){swap(p,q);return q;}
	int mid=l+r>>1,tmp=sum[ls[p]];
	if(x>tmp){
		rs[q]=splitl(rs[p],rs[q],mid+1,r,x-tmp);
		swap(ls[p],ls[q]);
	}
	else ls[q]=splitl(ls[p],ls[q],l,mid,x);
	pushup(p);pushup(q);return q;
}
int splitr(int &p,int q,int l,int r,int x){
	if(!q)q=++tot;
	if(!p||l==r){swap(p,q);return q;}
	int mid=l+r>>1,tmp=sum[rs[p]];
	if(x>tmp){
		ls[q]=splitr(ls[p],ls[q],l,mid,x-tmp);
		swap(rs[p],rs[q]);
	}
	else rs[q]=splitr(rs[p],rs[q],mid+1,r,x);
	pushup(p);pushup(q);return q;
}
void queryl(int k,int l,int r){
	if(!k)return;
	if(l==r){if(sum[k])printf("%c",bl[l]);return;}
	int mid=l+r>>1;
	queryl(ls[k],l,mid);
	queryl(rs[k],mid+1,r);
}
void queryr(int k,int l,int r){
	if(!k)return;
	if(l==r){if(sum[k])printf("%c",bl[l]);return;}
	int mid=l+r>>1;
	queryr(rs[k],mid+1,r);
	queryr(ls[k],l,mid);
	
}
int Splitl(int r){
	R=s.upper_bound(r);--R;y=*R;sum2=r-y+1;
	if(sum2==sum[root[y]])return y;
	root[r+1]=0;
	if(lazy[y])root[r+1]=splitl(root[y],root[r+1],1,n,sum[root[y]]-sum2);
	else root[r+1]=splitr(root[y],root[r+1],1,n,sum[root[y]]-sum2);
	lazy[r+1]=lazy[y];
	s.insert(r+1);return y;
}
int Splitr(int l){
	L=s.upper_bound(l);--L;x=*L;sum1=*(++L)-l;
	if(l==x)return l;root[l]=0;
	if(lazy[x])root[l]=splitl(root[x],root[l],1,n,sum1);
	else root[l]=splitr(root[x],root[l],1,n,sum1);
	lazy[l]=lazy[x];
	s.insert(l);
	return l;
}

int main(){
	scanf("%d%d%s",&n,&m,c+1);
	for(int i=1;i<=n;++i)++Cnt[int(c[i]-'a'+1)];
	for(int i=1;i<=26;++i)Cnt[i]+=Cnt[i-1];
	for(int i=1;i<=n;++i){
		x=++Cnt[int(c[i]-'a')];bl[x]=c[i];
		root[i]=insert(root[i],1,n,x);
		s.insert(i);
	}
	s.insert(n+1);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&l,&r,&opt);opt^=1;
		l=Splitr(l);r=Splitl(r);lazy[l]=opt;
		L=s.lower_bound(l);R=s.lower_bound(r);top=0;
		if(L==R)continue;++R;
		for(++L;L!=R;++L){root[l]=merge(root[l],root[*L],1,n);t[++top]=*L;};
		for(int j=1;j<=top;++j)s.erase(t[j]);
	}
	for(L=s.begin();L!=s.end();++L){
		if(lazy[*L])queryr(root[*L],1,n);
		else queryl(root[*L],1,n);
	}
	return 0;
}