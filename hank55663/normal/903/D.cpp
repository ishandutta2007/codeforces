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
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
int main(){
	map<int,int> m;
	int n;
	scanf("%d",&n);
	long double sum=0;
	long double res=0;
	for(int i=0;i<n;i++){
		LL a;
		scanf("%I64d",&a);
		res+=a*i-sum;
		res-=m[a-1];
		res+=m[a+1];
		sum+=a;
		m[a]++;
	}
	printf("%.0Lf\n",res);
}