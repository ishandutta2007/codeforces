#include<bits/stdc++.h>
#define N 30005
using namespace std;
struct data{
	int l,r,id,s;
	int operator < (const data &b)const{
		return s!=b.s?s<b.s:r<b.r;
  }
}Q[N];int n,m,sign,P,i,L,R,S;
int have[N<<2],w[N],b[N],U[N],pos[N],num[N],ans[N];
struct matrix{
	int p[2][2];
	inline matrix operator * (const matrix &b)const{
		matrix c;
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++){
				c.p[i][j]=0;
				for (int k=0;k<2;k++)
					c.p[i][j]+=p[i][k]*b.p[k][j];
				c.p[i][j]%=P;
		  }return c;
	}inline void operator += (const matrix &b){
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
				if ((p[i][j]+=b.p[i][j])>=P) p[i][j]-=P;
	}
}a[N<<2],Pow[N];
void Insert(int x,int l,int r,int pos){
	if (l==r){
		a[x].p[0][0]=a[x].p[0][1]=a[x].p[1][0]=sign*w[l];
		have[x]=sign;return;
  }int mid=(l+r)>>1;
  if (pos<=mid) Insert(x<<1,l,mid,pos);
  				else  Insert(x<<1|1,mid+1,r,pos);
  have[x]=have[x<<1]+have[x<<1|1];
  a[x]=a[x<<1];a[x]+=a[x<<1|1]*Pow[have[x<<1]];
}
int main(){
	scanf("%d%d",&n,&P);
	for (i=1;i<=n;i++)
		scanf("%d",&U[i]),b[i]=U[i];
	sort(U+1,U+n+1);
	*U=unique(U+1,U+n+1)-(U+1);
	for (i=1;i<=n;i++)
		w[pos[i]=lower_bound(U+1,U+*U+1,b[i])-U]=b[i]%P;
	Pow[0].p[0][0]=Pow[0].p[1][1]=1;
	Pow[1].p[0][0]=Pow[1].p[0][1]=Pow[1].p[1][0]=1;
	for (i=2;i<=n;i++)
		Pow[i]=Pow[i-1]*Pow[1];
	S=sqrt(n);
	scanf("%d",&m);
	for (i=1;i<=m;i++)
		scanf("%d%d",&Q[i].l,&Q[i].r),
		Q[i].id=i,Q[i].s=Q[i].l/S;
	sort(Q+1,Q+m+1);
	L=1;R=0;
	for (i=1;i<=m;i++){
		sign=1;
		for (;R<Q[i].r;)
			if ((++num[pos[++R]])==1) Insert(1,1,n,pos[R]);
		for (;L>Q[i].l;)
			if ((++num[pos[--L]])==1) Insert(1,1,n,pos[L]);
		sign=0;
		for (;R>Q[i].r;R--)
			if ((--num[pos[R]])==0) Insert(1,1,n,pos[R]);
		for (;L<Q[i].l;L++)
			if ((--num[pos[L]])==0) Insert(1,1,n,pos[L]);
		ans[Q[i].id]=a[1].p[0][1];
  }for (i=1;i<=m;i++)
  	printf("%d\n",ans[i]);
}