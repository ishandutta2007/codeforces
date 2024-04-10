#include <bits/stdc++.h>

using namespace std;

int x[105],y[105];

int main(){
	int n,k;
	scanf("%d%d", &n, &k);
	for(int i=0; i < n; ++i){
		scanf("%d%d",x+i,y+i);
	}
	double len=0;
	for(int i=0; i < n-1; ++i){
		double dx=x[i+1]-x[i],dy=y[i+1]-y[i];
		len += sqrt(dx*dx+dy*dy);
	}
	printf("%.7lf\n", k*len/50);
}