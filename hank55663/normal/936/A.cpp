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
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	LL k,d,t;
	scanf("%lld %lld %lld",&k,&d,&t);
	t*=2;
	LL last=d-k%d;
	if(last==d)
	last=0;
	k=(k/d+(k%d!=0))*d;
	LL ti=k*2-last;
	LL ans=t/ti*k;
	//printf("%d %d %d\n",t,ti,k);
	LL las=t%ti;
	double add=0;
	if(las>k*2-last*2){
		add+=(k-last);
		las-=k*2-last*2;
		add+=las;
	}
	else{
		add+=las/2.0;
	}
	printf("%.2lf\n",add+ans);
}