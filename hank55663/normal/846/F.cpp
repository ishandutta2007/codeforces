#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
using namespace std;
vector<int> v[1000005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<=1e6;i++)
	v[i].pb(0);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		v[a].pb(i);
	}
	LL sum=0;
	for(int i=1;i<=1e6;i++)
	{
		for(int j=1;j<v[i].size();j++){
			sum+=(LL)(v[i][j]-v[i][j-1])*(n-v[i][j]+1);
		}
	}
	sum=(sum-n)*2+n;
	//printf("%d\n",sum);
	printf("%lf\n",(double)sum/n/n);
}