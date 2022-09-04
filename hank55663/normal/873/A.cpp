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
#define pi 3.14159265359
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
const int inf=1000000000;
#define MAXN 10000
int main() {
	int n,k,x;
	scanf("%d %d %d",&n,&k,&x);
	int a[105];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<k;i++){
		if(a[n-i-1]>x)
		a[n-i-1]=x;
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	printf("%d\n",sum);
}