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
#define next Next
using namespace std;
typedef long long LL;
int main(){
	int a[3];
	scanf("%d %d %d",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	if(a[0]==1){
		printf("YES\n");
		return 0;
	}
	else if(a[1]==2){
		printf("YES\n");
		return 0;
	}
	else if(a[2]==3&&a[0]==3){
		printf("YES\n");
		return 0;
	}
	else if(a[0]==2&&a[1]==4&&a[2]==4){
		printf("YES\n");
		return 0;
	}
	printf("NO\n"); 
	
}