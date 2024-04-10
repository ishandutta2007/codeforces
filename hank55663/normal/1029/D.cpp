#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
#define N
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	map<int,int> m[11];
	int a[200005];
	LL ans=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		LL x=a[i];
		for(int j=1;j<=10;j++){
			x*=10;
			x%=k;
			m[j][x]++;
			//if(j==1)
			//printf("%d ",x%k);
		}
	}
//	printf("\n");
	for(int i=0;i<n;i++){
		LL x=a[i];
		int cnt=0;
		while(x&&++cnt){
			x/=10;
		}
		x=a[i];
		for(int j=0;j<cnt;j++)
		x*=10,x%=k;
		if((x+a[i])%k==0)
		ans--;
		ans+=m[cnt][(k-a[i]%k)%k];
	//	printf("%d %d %d\n",ans,a[i],cnt);
	}
	printf("%lld\n",ans);
}
/*
   s       20006
 qqqqqq  0~10000
bbbbbbbb  10001 20000
  5 5 5    20001 20005
     t    20007





*/