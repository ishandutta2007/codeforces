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
int ini[1005];
int now[1005];
int add[1005];
int p[1005];
int main(){
	int n,m,c;
	scanf("%d %d %d",&n,&m,&c);
	for(int i=1;i<=c;i++){
		if(i<=c/2)
		now[i]=1;
		else
		now[i]=n;
	//	printf("%d ",ini[i]);
	}
	MEM(p);
	while(m--){
		int x;
		scanf("%d",&x);
		printf("%d\n",now[x]);
		p[now[x]]=x;
	//	printf("?");
		if(x<=c/2){
			for(int i=x+1;i<=c/2;i++){
				if(now[i]==now[x]){
					now[i]++;
				}
			//	printf("%d",i);
			}
			now[x]++;
		}
		else{
			for(int i=c/2+1;i<=x;i++){
				if(now[i]==now[x])
				now[i]--;
			//	printf("%d",i);
			}		
		}
	//	for(int i=1;i<=c;i++)
	//	printf("%d ",now[i]);
	//	printf("?");
		fflush(stdout);
		int ok=1;
		for(int i=1;i<=n;i++){
			if(p[i]==0)
			ok=0;
			if(i>=2&&p[i]<p[i-1])
			ok=0;
		}
		if(ok)
		break;
	}
	//assert(m>=0);
}