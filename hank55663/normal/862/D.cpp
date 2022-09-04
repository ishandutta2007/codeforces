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
	int n;
	scanf("%d",&n);
	int ans0=0,ans1=0;
	printf("? ");
	for(int i=0;i<n;i++)
	printf("1");
	printf("\n");
	fflush(stdout);
	int now; 
	scanf("%d",&now);
	printf("? ");
	for(int i=0;i<n-1;i++)
	printf("1");
	printf("0");
	printf("\n");
	fflush(stdout);
	int now2;
	scanf("%d",&now2);
	if(now2>now)
	ans1=n;
	else ans0=n;
	int l=0,r=n-1;
	while(l<r-1){
		int mid=(l+r)/2;
		printf("? ");
		for(int i=0;i<n;i++){
			if(i>=l&&i<mid)
			printf("0");
			else
			printf("1");
		}
		printf("\n");
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if(ans0==n){
			if(mid-l==now-x){
				l=mid;
			}
			else{
				r=mid;
			}
		}
		else{
			if(mid-l==x-now){
				l=mid;
			}
			else{
				r=mid;
			}
		}
	}
	if(ans0==0)
	ans0=l+1;
	else
	ans1=l+1;
	printf("! %d %d\n",ans0,ans1);
	fflush(stdout);
}