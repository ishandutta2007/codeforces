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
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	if(n==2){
		printf("3\n2 1 2 \n");
	}
	else if(n%2==0){
		printf("%d\n",n/2*3);
		for(int i=2;i<=n;i+=2){
			printf("%d %d ",i,i-1);
		}
		for(int i=2;i<=n;i+=2){
			printf("%d ",i);
		}
	}
	else{
		printf("%d\n",n/2*3+1);
		for(int i=2;i<=n;i+=2){
			printf("%d %d ",i,i-1);
		}
		printf("%d ",n);
		for(int i=2;i<=n;i+=2){
			printf("%d ",i);
		}
	}
} 

//9
//      5
// 1 2 3 4     6 7 8 9