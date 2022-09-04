#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	if(m<n)
	swap(m,n);
	if(n==1){
		int ans=m-m%6;
		if(m%6==4)
		ans+=2;
		if(m%6==5)
		ans+=4;
		printf("%d\n",ans);
	}
	else if(n==2){
		if(m%2==1){
		    if(m==5||m>7)
		    printf("%d\n",n*m);
		    else
			printf("%d\n",n*m-2);
		}
		else if(m==2){
			printf("0\n");
		}
		else{
			printf("%d\n",n*m);
		}
	}
	else{
		LL ans=(LL)n*m;
		printf("%lld\n",ans-ans%2);
	}
}