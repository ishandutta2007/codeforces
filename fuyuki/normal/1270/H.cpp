#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1<<20;
int n,m,a[N],c[N],tag[N<<2],cnt[N<<2];
void update(int p,int l,int r){
	if(l==r)cnt[p]=!!c[l]*!tag[p];
	else cnt[p]=(cnt[p<<1]+cnt[p<<1|1])*!tag[p];
}
void modify(int p,int L,int R,int l,int r,int x){
	if(L==l&&R==r)return tag[p]+=x,update(p,L,R);
	int mid=L+R>>1;
	if(l>mid)modify(p<<1|1,mid+1,R,l,r,x);
	else if(r<=mid)modify(p<<1,L,mid,l,r,x);
	else modify(p<<1,L,mid,l,mid,x),modify(p<<1|1,mid+1,R,mid+1,r,x);
	update(p,L,R);
}
void settle(int x,int w){if(a[x]>a[x-1])modify(1,1,N,a[x-1]+1,a[x],w);}
void init(int x,int w){settle(x,w),settle(x+1,w);}
void ins(int x,int w){c[x]+=w,modify(1,1,N,x,x,0);}
int main(){
	scanf("%d%d",&n,&m),a[0]=N;
	FOR(i,1,n)scanf("%d",a+i),ins(a[i],1),settle(i,1);
	for(int x,y;m--;){
		scanf("%d%d",&x,&y),init(x,-1),ins(a[x],-1);
		ins(a[x]=y,1),init(x,1),printf("%d\n",cnt[1]);
	}
	return 0;
}