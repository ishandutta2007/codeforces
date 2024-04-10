#pragma GCC optimize(2) 
#include<bits/stdc++.h>
using namespace std;
#define B 500
#define N 150005
#define ull unsigned long long
char buf[1<<20],*p1=buf,*p2=buf,ch;
int result;
#define getc() p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++;
inline int re(){
    ch=getc();result=0;
    while (ch<'0'||ch>'9') ch=getc();
    while (ch>='0'&&ch<='9') result=result*10+(ch^48),ch=getc();
    return result;
}
int OO,E,l,r,A[N],L[N],V,mx,R[N],a[N],cnt,oo,val[N],K[N],v[B];
short C[N];
int chs(int pos){
	if(v[K[pos]])return v[K[pos]];
	return A[pos];
}
struct query{
	int x,y;
}q[N];
inline bool cmp(query aa,query bb){return aa.y>bb.y;}
int n,m,p,i,j,typ,x,tot,ans[20],bg,cl,CL;
int main(){
	ios::sync_with_stdio(0);
	n=re();m=re();p=re();
	mx=100/p;
	mt19937_64 rnd(0);
	for(i=1;i<=n;++i)A[i]=re();
	for(i=1;i<=n;i+=B){
		l=i;r=min(n,i+B-1);++cnt;
		for(j=l;j<=r;++j)L[j]=l,R[j]=r,K[j]=cnt;
	}
	while(m--){
		typ=re();l=re();r=re();
		++OO;
		if(typ^2){
			x=re();
			if(l>=r-B){
				for(i=L[l];i<=R[r];++i)if(v[K[i]])A[i]=v[K[i]];
				v[K[l]]=v[K[r]]=0;
				for(i=l;i<=r;++i)A[i]=x;
			}
			else{
				E=K[l];
				E=v[E];
				if(E)for(i=L[l];i<l;++i)A[i]=E;
				v[E=K[l]]=0;
				for(i=l;i<=R[l];++i)A[i]=x;
				for(i=R[l]+1;i<L[r];i+=B)v[K[i]]=x;
				E=K[r];
				for(i=L[r];i<=r;++i)A[i]=x;
				if(E=v[E])for(;i<=R[r];++i)A[i]=E;
				v[E=K[r]]=0;
			}
		}
		else{
			cnt=tot=0;V=((r-l+1)*p+99)/100;
			if(l>=r-B){
				for(i=l;i<=r;++i)a[++cnt]=chs(i);
				for(i=1;i<=cnt;++i)++C[a[i]];
				for(i=1;i<=cnt;++i){
					if(C[a[i]]>=V)ans[++tot]=a[i];
					C[a[i]]=0;
				}
			}
			else{
				r-=l-1;
				for(i=1;i<=840;++i)++C[a[i]=chs(rnd()%r+l)];
				r+=l-1;
				tot=0;
				for(i=1;i<=840;++i){
					if(C[a[i]]>28)
						q[++tot].x=a[i],q[tot].y=C[a[i]];
					C[a[i]]=0;
				}
				sort(q+1,q+tot+1,cmp);
				if(tot>mx)tot=mx;
				for(i=1;i<=tot;++i)ans[i]=q[i].x;
			}
			printf("%d ",tot);
			for(i=1;i<=tot;++i)printf("%d ",ans[i]);
			putchar('\n');
		}
	}
}