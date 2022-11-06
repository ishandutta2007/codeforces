#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
double ax,ay,bx,by,tx,ty;
int n;
double x[N],y[N];
double dist(double a,double b,double x,double y){
	return sqrt((a-x)*(a-x)+(b-y)*(b-y));
}
double work(){
	cin>>ax>>ay>>bx>>by>>tx>>ty;
	cin>>n;
	double f[4]={0,1e20,1e20,1e20};
	for(int i=0;i<n;++i){
		double g[4];
		memcpy(g,f,sizeof f);
		cin>>x[i]>>y[i];
		double d=dist(x[i],y[i],tx,ty);
		double u=dist(x[i],y[i],ax,ay);
		double v=dist(x[i],y[i],bx,by);
		f[0]=g[0]+2*d;
		f[1]=min(g[1]+2*d,g[0]+u+d);
		f[2]=min(g[2]+2*d,g[0]+v+d);
		f[3]=min(g[3]+2*d,min(g[1]+v+d,g[2]+u+d));
	}
	return min(f[1],min(f[2],f[3]));
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);//cin.tie(0);
	cout<<fixed<<setprecision(10)<<work()<<"\n";
}