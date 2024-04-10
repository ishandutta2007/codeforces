#include <bits/stdc++.h>

using namespace std;

int n;
int x[305],y[305];
int dpMax[305];
int dpMin[305];

int area(int i, int j, int k){
	return x[i]*y[j]-x[j]*y[i]+x[j]*y[k]-x[k]*y[j]+x[k]*y[i]-x[i]*y[k];
}

int main(){
	scanf("%d", &n);
	for(int i=0; i < n; ++i)
		scanf("%d%d", x+i, y+i);
	int ans=0;
	for(int i=0; i < n; ++i){
		for(int k=0; k < n; ++k){
			dpMax[k]=-999999999;
			dpMin[k]=999999999;
		}
		for(int j=0; j < n; ++j)
			for(int k=0; k < n; ++k){
				int a=area(i,j,k);
				if(a == 0)
					continue;
				dpMax[k]=max(dpMax[k],a);
				dpMin[k]=min(dpMin[k],a);
			}
		for(int k=0; k < n; ++k)
			ans=max(ans, dpMax[k]-dpMin[k]);
	}
	printf("%.9lf\n", ans/2.0);
}