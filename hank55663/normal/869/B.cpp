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
#define MAXD 2
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	LL a,b;
	scanf("%I64d %I64d",&a,&b);
	if(b-10>a){
		printf("0\n");
	}
	else{
		LL last=1;
		for(LL i=b;i>a;i--)
		{
			last*=i%10;
		}
		printf("%I64d\n",last%10);
	}
} 
//200 2048 11
//10 
//01 
//1001 
//10011