#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int a[100005];
	int b[100005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<m;i++)
	scanf("%d",&b[i]);
	sort(a,a+n);
	sort(b,b+m);
	for(int i=n-1,j=m-1;i>=0&&j>=0;i--,j--){
		
		if(a[i]>b[j]){
			printf("YES\n");
			return 0;
		}
	}
	if(n>m){
		printf("YES\n");
	}
	else
	printf("NO\n");
	return 0;
}