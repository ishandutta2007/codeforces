#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int n,u;
	scanf("%d %d",&n,&u);
	int e[100005];
	for(int i=0;i<n;i++)
	scanf("%d",&e[i]);
	double ans=-1;
	int j=2;
	for(int i=0;i<n-2;i++){
		while(e[j]-e[i]<=u&&j<n)
		j++;
		if(j-i>2){
			ans=max(ans,(double)(e[j-1]-e[i+1])/(e[j-1]-e[i]));
		}
	}
	if(ans<0)
	printf("-1\n");
	else
	printf("%.12lf\n",ans);
}