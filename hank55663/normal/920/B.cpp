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
#define index Index
#define N 300005
using namespace std;
typedef long long LL;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		queue<pii> q;
		int n;
		scanf("%d",&n);
		int now=0;
		for(int i=0;i<n;i++){
			int l,r;
			scanf("%d %d",&l,&r);
			q.push(mp(l,r)); 
		}
		while(!q.empty()){
			pii p=q.front();
			q.pop();
			if(now>p.y)
			printf("0 ");
			else{
				printf("%d ",max(now,p.x));
				now=max(now+1,p.x+1);
			}
		}
		printf("\n");
	} 
}