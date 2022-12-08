#include<bits/stdc++.h>
using namespace std;
const int N=1010;
const double eps=1e-6;
double f[N][N];
void calc(int n,int m) {
	if(f[n][m]>eps)return;
	if(n==0)f[n][m]=1.0/(m+1);
	if(m==0)f[n][m]=1;
	if(!n||!m)return;
	calc(m,n-1);
	calc(m-1,n);
	double w11=m*(1-f[m-1][n])/(m+1),w12=1.0/(m+1)+w11;
	double w21=1,w22=1-f[m][n-1];
	double p=(w21-w22)/(w12+w21-w11-w22);
	f[n][m]=p*w11+(1-p)*w21;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	calc(n,m);
	printf("%.11f %.11f\n",f[n][m],1-f[n][m]);
	return 0;
}