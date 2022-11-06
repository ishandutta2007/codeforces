#include<bits/stdc++.h>
using namespace std;
const int N=35011,inf=~0u>>2;
struct Seg{
	int mx,ad;
	inline void add(int t){mx+=t,ad+=t;}
}T[N<<2];
inline void push_up(int o){T[o].mx=max(T[o<<1].mx,T[o<<1|1].mx);}
inline void push_down(int o){T[o<<1].add(T[o].ad),T[o<<1|1].add(T[o].ad),T[o].ad=0;}
#define mid (L+R>>1)
#define lson L,mid,o<<1
#define rson mid+1,R,o<<1|1
void clr(int L,int R,int o){
	T[o].mx=-inf,T[o].ad=0;
	if(L==R)return;
	clr(lson),clr(rson);
}
void updata(int L,int R,int o,int l,int r){
	if(L==l&&R==r){T[o].add(1);return;}
	if(T[o].ad)push_down(o);
	if(r<=mid)updata(lson,l,r);
	else if(l>mid)updata(rson,l,r);
	else updata(lson,l,mid),updata(rson,mid+1,r);
	push_up(o);
}
void Add(int L,int R,int o,int v,int x){
	if(L==R){T[o].mx=x;return;}
	if(T[o].ad)push_down(o);
	if(v<=mid)Add(lson,v,x);
	else Add(rson,v,x);
	push_up(o);
}
int n,K,a[N],lst[N];
int f[52][N];
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=K;i++){
		clr(0,n,1);
		memset(lst,0,sizeof lst);
		Add(0,n,1,i-1,f[i-1][i-1]);
		for(int j=i;j<=n;j++){
			updata(0,n,1,lst[a[j]],j-1);
			lst[a[j]]=j;
			f[i][j]=T[1].mx;
			Add(0,n,1,j,f[i-1][j]);
		}
	}
	printf("%d\n",f[K][n]);
}