#include<bits/stdc++.h>
using namespace std;
struct Basis{
	int p[35];
	void Clear(){
		memset(p,0,sizeof(p));
	}
	void Insert(int x){
		for(int i=29;i>=0;i--){
			if(!(x&(1<<i)))continue;
			if(!p[i]){
				p[i]=x;
				return ;
			}
			else x^=p[i];
		}
	}
	int Query(){
		int cnt=0;
		for(int i=29;i>=0;i--)if(p[i])cnt++;
		return 1<<cnt;
	}
}t[800005];
int c[800005],a[800005],n,m;
Basis operator +(Basis a,Basis b){
	for(int i=0;i<=29;i++)if(b.p[i])a.Insert(b.p[i]);
	return a;
}
void Build(int p,int l,int r){
	if(l==r)return t[p].Insert(a[l]),void();
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	t[p]=t[p*2]+t[p*2+1];
}
Basis Query(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y)return t[p];
	int mid=(l+r)/2;
	if(y<=mid)return Query(p*2,l,mid,x,y);
	if(x>mid)return Query(p*2+1,mid+1,r,x,y);
	return Query(p*2,l,mid,x,y)+Query(p*2+1,mid+1,r,x,y);
}
void Upd(int p,int l,int r,int x,int y){
	if(l==r)return t[p].Clear(),t[p].Insert(a[l]^=y),void();
	int mid=(l+r)/2;
	if(x<=mid)Upd(p*2,l,mid,x,y);
	else Upd(p*2+1,mid+1,r,x,y);
	t[p]=t[p*2]+t[p*2+1];
}
void U(int x,int k){
	while(x<=n)c[x]^=k,x+=x&-x;
}
int Q(int x){
	int r=0;
	while(x)r^=c[x],x-=x&-x;
	return r;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)U(i,a[i]^=a[i-1]);
	Build(1,1,n);
	for(int i=1,opt,x,y,z;i<=m;i++){
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1){
			scanf("%d",&z),U(x,z),Upd(1,1,n,x,z);
			if(y<n)U(y+1,z),Upd(1,1,n,y+1,z);
		}
		else {
			Basis o;
			o.Clear(),o.Insert(Q(x));
			if(x<y)o=o+Query(1,1,n,x+1,y);
			printf("%d\n",o.Query());
		}
	}
}