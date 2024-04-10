#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=200005,NC=(1<<19)+5;
struct mat{
	double a[3][3];
	mat(){for(int i=0;i<3;++i)for(int j=0;j<3;++j)a[i][j]=-1e18;}
	mat operator * (const mat &o)const{
		mat c;for(int i=0;i<3;++i)for(int k=0;k<3;++k)for(int j=0;j<3;++j)chmax(c.a[i][j],a[i][k]+o.a[k][j]);
		return c;
	}
}I,f[NC];int M,a[N];double v[3];bool can[3][3];
inline mat get(int x){
	mat c;for(int i=0;i<3;++i)for(int j=0;j<3;++j)if(can[i][j])c.a[i][j]=x*v[i];
	return c;
}
void build(int n){
	for(M=1;M<=n+2;M<<=1);
	std::fill(f,f+M*2+3,I);
	for(int i=1;i<=n;++i)f[i+M]=get(a[i]);
	for(int i=M-1;i>=1;--i)f[i]=f[i<<1|1]*f[i<<1];
}
void upd(int x){f[x+M]=get(a[x]);for(x=(x+M)>>1;x;x>>=1)f[x]=f[x<<1|1]*f[x<<1];}
mat ask(int s,int t){
	mat A=I,B=I;
	for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1){
		if(~s&1)A=f[s^1]*A;
		if(t&1)B=B*f[t^1];
	}
	return B*A;
}
int main(){
	for(int i=0;i<3;++i)I.a[i][i]=0;
	int n,q,x,y;read(n,q,x,y),v[0]=0,v[1]=1.0/std::max(x,y),v[2]=1.0/(x+y);
	for(int i=0;i<3;++i)for(int j=0;j<3;++j)can[i][j]=x*v[i]+y*v[j]<=1+1e-9&&y*v[i]+x*v[j]<=1+1e-9;
	for(int i=1;i<=n;++i)read(a[i]);
	build(n);int opt,l,r,k,v;
	while(q--){
		read(opt);
		if(opt==1)read(k,v),a[k]=v,upd(k);
		else{
			read(l,r);mat tmp=ask(l,r);double mx=0;
			for(int i=0;i<3;++i)mx=std::max(mx,tmp.a[i][0]);
			printf("%.12lf\n",mx);
		}
	}
	return 0;
}