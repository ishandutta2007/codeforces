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
#define next Next
using namespace std;
typedef long long LL;
int need[300005];
void dfs(int i){
	if(need[i]==0)
	return;
	printf("(");
	dfs(i+1);
	printf(")");
	need[i]--;
	while(need[i])
	{
		printf("()");
		need[i]--;
	}
} 
int main(){
	LL n,k;
	scanf("%I64d %I64d",&n,&k);
	MEM(need);
	int now=n;
	int i;
	for(i=0;k>=i;i++){
		need[i]++;
		now--;
		if(now<0)
		break;
		k-=i;
	}
	if(now>=0)
	for(i--;i>0;i--){
		while(k>=i){
			need[i]++;
			now--;
			k-=i;
		}
	}
	if(now<0){
		printf("Impossible\n");
	}
	else{
		need[0]+=now;
		dfs(0);		
	}
}