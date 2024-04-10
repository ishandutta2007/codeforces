#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
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
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
int main(){
	int n,d;
	scanf("%d %d",&n,&d);
	int a[100005];
	int now=0;
	int ans=0;
	int over=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){
			if(now+over<0){
				now=0;
				ans++;
				over=d;
			}
			else if(now<0){
				over+=now;
				now=0;
			}
		}
		else{
			now+=a[i];
		}
		over=min(over,d-now);
		if(now>d){
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n",ans);
}