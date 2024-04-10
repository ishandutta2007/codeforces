#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 800005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
using namespace std;
typedef long long LL;

int main()
{
	int a,b,c,d,e;
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	if(a*b+d*2>a*c+e*2){
		printf("Second\n");
	}
	else if(a*b+d*2<a*c+e*2){
		printf("First\n");
	}
	else
	printf("Friendship\n");
}