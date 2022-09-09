#include<bits/stdc++.h>
using namespace std;
int xx[1010];
long double x[1010],y[1010];
int r;
long double te(int i,int j){
	if(abs(xx[i]-xx[j])>2*r)return r;
	return y[j]+sqrt(4*r*r-(xx[i]-xx[j])*(xx[i]-xx[j]));
}
int main(){
	int n;
	cin>>n;
	cin>>r;
	for(int i=0;i<n;++i){
		cin>>xx[i];
		x[i]=xx[i];
		y[i]=r;
		for(int j=0;j<i;++j)if(te(i,j)>y[i])y[i]=te(i,j);
	}
	for(int i=0;i<n;++i)cout<<setprecision(15)<<y[i]<<" ";
}