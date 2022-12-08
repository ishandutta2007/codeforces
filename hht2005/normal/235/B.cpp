#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
double p[N],f[N][3];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf",p+i);
	for(int i=1;i<=n;i++) {
		f[i][0]=(f[i-1][0]+1)*p[i];
		f[i][1]=f[i-1][1]+(2*f[i-1][0]+1)*p[i];
	}
	printf("%.15f\n",f[n][1]);
	return 0;
}