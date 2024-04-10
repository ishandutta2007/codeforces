#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
	int x,y;
	cin >> x >> y;
	double ok[x],of[x];
	double p,q;
	for(int i=0; i<x ;i++){
		cin >> p >> q;
		of[i]=q-p+1;
		ok[i]=floor(q/y)-floor((p-1)/y);
	}
	double cost;
	double ans=0;
	for(int i=0; i<x-1 ;i++){
		cost=1-(1-ok[i]/of[i])*(1-ok[i+1]/of[i+1]);
		ans+=cost;
	}
	cost=1-(1-ok[0]/of[0])*(1-ok[x-1]/of[x-1]);
	ans+=cost;
	ans*=2000;
	printf("%lf\n", ans);
}