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
bool cmp(const pair<pii,int> &a,const pair<pii,int> &b){
	if(a.x.x!=b.x.x)
	return a.x.x>b.x.x;
	return a.x.y<b.x.y;
}
int main(){
	int n,k,m,a;
	scanf("%d %d %d %d",&n,&k,&m,&a);
	pair<pii,int> vote[105];
	MEM(vote);
	for(int i=1;i<=n;i++){
		vote[i]=mp(mp(0,0),i);
	}
	for(int i=0;i<a;i++){
		int x;
		scanf("%d",&x);
		vote[x]=mp(mp(vote[x].x.x+1,i),x);
	}
	if(n==1){
		printf("1");
		return 0;
	}
	if(k==n){
		for(int i=1;i<=n;i++){
			if(vote[i].x.x){
				printf("1 ");
			}
			else{
				if(m!=a)
				printf("2 ");
				else
				printf("3 ");
			}
		}
		return 0;
	}
	sort(vote+1,vote+n+1,cmp);
	int last=m-a;
	int ans[105];
	MEM(ans);
	for(int i=1;i<=n;i++){
//		printf("%d %d %d\n",vote[i].x.x,vote[i].y,last);
		int ok1=0,ok2=0;
		int need=vote[i].x.x+1;
		int sum=0;
		for(int j=i+1;j<=k+1;j++){
			sum+=need-vote[j].x.x;
		}
		if(sum>last&&vote[i].x.x&&i<=k){
			ok1=1;
		}
		if(vote[i].x.x+last>vote[k].x.x){
			ok2=1;
		}
		if(ok1){
			ans[vote[i].y]=1;
		}
		else if(ok2){
			ans[vote[i].y]=2;
		}
		else{
			ans[vote[i].y]=3;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
}