#include<bits/stdc++.h>
using namespace std;
using ld=long double;
#define double ld
const int N=1011;
int n;
double x[N],y[N];
double G(int i,int j,int k){
	double a=y[k]-y[i];
	double b=x[i]-x[k];
	double c=x[k]*y[i]-y[k]*x[i];
	double d=abs(a*x[j]+b*y[j]+c)/sqrt(a*a+b*b);
	#define EPS (1e-10)
	if(abs(x[i]-x[k])<EPS) d=abs(x[j]-x[i]);
	else if(abs(y[i]-y[k])<EPS) d=abs(y[j]-y[i]);
	return d;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>x[i]>>y[i];
	double ans=1e18;
	for(int i=0;i<n;++i){
		int j=(i+1)%n;
		int k=(i+2)%n;
		ans=min(ans,G(i,j,k)*0.5);
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
}