#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int x,d;
	scanf("%d %d",&x,&d);
	LL ans[100000];
	ans[0]=-d+1;
	int index=0;
	while(x){
		for(int i=1;;i++){
			if((1<<i)-1>x){
				i--;
				x-=((1<<i)-1);
				ans[index+1]=ans[index]+d;
				for(int j=index+2;j<=index+i;j++){
					ans[j]=ans[j-1];
				}
				index=index+i;
				break;
			}
		}
	}
	printf("%d\n",index);
	for(int i=1;i<=index;i++)
	printf("%lld ",ans[i]);
}