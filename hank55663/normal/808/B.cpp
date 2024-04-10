//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a[N];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	LL sum[N];
	sum[0]=0;
	for(int i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i-1];
	double ans=0;
	for(int i=k;i<=n;i++)
	ans+=(double)(sum[i]-sum[i-k])/(n-k+1);
	printf("%.10lf\n",ans);
} 
// 10010
//1 1 2 6 3 8 4 11 5 17 6 15 7 13 8 25 9 22 10 27
//1
//2 4 6 8 10
//3 6 9
//4 2 6 8 10
//5 5 10
//6 2 3 4 6 8 10