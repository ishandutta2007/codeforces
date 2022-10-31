#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef long long ll;
#define double long double
struct mat{
	double a[3][3];
	mat(){memset(a,0,sizeof(a));}
	mat operator * (const mat &o)const{
		mat c;for(int i=0;i<3;++i)for(int k=0;k<3;++k)for(int j=0;j<3;++j)c.a[i][j]+=a[i][k]*o.a[k][j];
		return c;
	}
}I,f[N],pw[35];
mat ksm(mat a,ll b){mat res=I;while(b){if(b&1)res=res*a;a=a*a,b>>=1;}return res;}
int t[N],a[N],b[N],st[N],top;double p[N],x[N],y[N];
inline double cross(double x1,double y1,double x2,double y2){return x1*y2-x2*y1;}
int main(){
	for(int i=0;i<3;++i)I.a[i][i]=1;
	int n;ll T;read(n,T);double val=0;
	for(int i=1;i<=n;++i)scanf("%d%d%Lf",&a[i],&b[i],&p[i]),x[i]=-p[i],y[i]=p[i]*a[i],val=std::max(val,b[i]*p[i]);
	std::iota(t+1,t+n+1,1),std::sort(t+1,t+n+1,[&](int a,int b){return x[a]==x[b]?y[a]<y[b]:x[a]<x[b];});
	for(int I=1;I<=n;++I){
		int i=t[I];while(top>=2&&cross(x[i]-x[st[top-1]],y[i]-y[st[top-1]],x[st[top]]-x[st[top-1]],y[st[top]]-y[st[top-1]])<=0)--top;
		st[++top]=i;
	}
	for(int i=1;i<=top;++i){
		int x=st[i];f[i].a[0][0]=1-p[x],f[i].a[0][1]=p[x]*val,f[i].a[0][2]=p[x]*a[x];
		f[i].a[1][1]=f[i].a[1][2]=f[i].a[2][2]=1;
	}
	ll cur=0;mat v;v.a[0][0]=0,v.a[1][0]=0,v.a[2][0]=1;
	for(int i=top;i>=1;--i){
		if(i==1)v=ksm(f[i],T-cur)*v;
		else{
			pw[0]=I;for(int j=1;j<35;++j)pw[j]=pw[j-1]*pw[j-1]*f[i];
			for(int j=34;j>=0;--j)if(cur+(1LL<<j)<=T){
				mat tmp=pw[j]*v,a=f[i-1]*tmp,b=f[i]*tmp;
				if(a.a[0][0]<=b.a[0][0])cur+=1LL<<j,v=b;
			}
		}
	}
	printf("%.12Lf\n",v.a[0][0]);
	return 0;
}