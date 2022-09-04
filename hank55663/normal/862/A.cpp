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
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	int a[1005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
	int now=0;
	int ans=0;
	for(int i=0;i<n;i++){
		while(now!=a[i])
		{
			if(now==x)
			break;
			now++;
			ans++;
		}
		if(a[i]==x)
		ans++;
		if(now==x)
		break;
		now++;
	}
	while(now!=x){
		now++;
		ans++;
	}
	printf("%d\n",ans);
}