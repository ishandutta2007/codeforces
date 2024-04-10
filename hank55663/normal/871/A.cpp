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
int main() {
	int q;
	scanf("%d",&q);
	while(q--){
		int n;
		scanf("%d",&n);
		if(n<4||n==5||n==7||n==11){
			printf("-1\n");
		}
		else{
			if(n%4==0){
				printf("%d\n",n/4);
			}
			if(n%4==2){
				printf("%d\n",n/4);
			}
			if(n%4==1){
				printf("%d\n",n/4-1);
			}
			if(n%4==3){
				printf("%d\n",n/4-1);
			}
		}
	}
}