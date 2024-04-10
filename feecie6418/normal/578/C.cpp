#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,a[200005];
double f(double x){
	double s=0,mn=0,mx=0,mins=2e9,maxs=-2e9;
	for(int i=1;i<=n;i++){
		s+=a[i]-x;
		mins=min(mins,s-mx);
		maxs=max(maxs,s-mn);
		mn=min(mn,s),mx=max(mx,s);
	}
	return max(fabs(mins),fabs(maxs));
}
int main() {
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	double l=-1e4,r=1e4;
	for(int i=1;i<=100;i++){
		double p=(l*2+r)/3,p2=(l+r*2)/3;
		if(f(p)<f(p2))r=p2;
		else l=p;
	}
	printf("%.10lf\n",f(l));
	return 0;
}