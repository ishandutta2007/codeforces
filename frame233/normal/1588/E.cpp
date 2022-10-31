#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=3005;const double PI=acos(-1),eps=1e-8;
double L[N],R[N],a[N],b[N];bool tag[N],can[N][N];
int x[N],y[N];
int main(){
	int n,r;read(n,r);
	for(int i=1;i<=n;++i)read(x[i],y[i]);
	for(int i=1;i<=n;++i){
		int m=0;
		for(int j=1;j<=n;++j){
			double d=sqrt(1LL*(x[i]-x[j])*(x[i]-x[j])+1LL*(y[i]-y[j])*(y[i]-y[j]));
			if(d<=r)continue;
			double X=atan2(y[j]-y[i],x[j]-x[i]),D=asin(r/d),l=X-D,r=X+D;
			if(r>PI)l-=PI*2,r-=PI*2;
			++m,a[m]=l,b[m]=r;
		}
		bool flag=0;for(int j=1;j<=m;++j)flag|=-PI<=a[j];
		if(flag){
			L[i]=-PI,R[i]=PI;
			for(int j=1;j<=m;++j)if(-PI<=a[j])L[i]=std::max(L[i],a[j]),R[i]=std::min(R[i],b[j]);
			for(int j=1;j<=m;++j)if(a[j]<-PI){
				if(b[j]<L[i]&&a[j]+PI*2.0>R[i]){L[i]=PI,R[i]=-PI;break;}
				if(R[i]<0)R[i]=std::min(R[i],b[j]);
				else L[i]=std::max(L[i],a[j]+PI*2.0);
			}
		}
		else{
			tag[i]=1;L[i]=PI,R[i]=-PI;
			for(int j=1;j<=m;++j)L[i]=std::min(L[i],b[j]),R[i]=std::max(R[i],a[j]+PI*2);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)if(i!=j){
			double ang=atan2(y[j]-y[i],x[j]-x[i]);bool flag;
			if(!tag[i])flag=L[i]<=ang+eps&&ang-eps<=R[i];
			else flag=ang-eps<=L[i]||ang+eps>=R[i];
			can[i][j]=flag;
		}
	}
	int ans=0;for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)if(can[i][j]&&can[j][i])++ans;
	printf("%d\n",ans);
	return 0;
}