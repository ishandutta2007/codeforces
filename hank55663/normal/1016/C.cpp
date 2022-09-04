#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
LL tot[2][300005];
LL ans[2][300005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<2;i++)
		for(int j=0;j<n;j++)
			scanf("%lld",&ans[i][j]);
	tot[0][n-1]=ans[0][n-1]*2+ans[1][n-1];
	tot[1][n-1]=ans[1][n-1]*2+ans[0][n-1];
	LL sum=ans[0][n-1]+ans[1][n-1];
	//printf("%lld %lld\n",tot[0][n-1],tot[1][n-1]);
	for(int i=n-2;i>=0;i--){
		tot[0][i]=ans[0][i]*(n-i)*2+ans[1][i]+tot[0][i+1]+sum;
		tot[1][i]=ans[1][i]*(n-i)*2+ans[0][i]+tot[1][i+1]+sum;
		sum+=ans[0][i]+ans[1][i];
	//	printf("%lld %lld\n",tot[0][i],tot[1][i]);
	}
	LL ret=0;
	LL ssum=sum*n*2;
//	printf("%lld\n",tot[0][0]);
	ret=ssum-tot[0][0];
//	printf("%lld\n",ret);
	sum=0;
	LL t=2*n;
	for(int i=0;i<n-1;i++){
		if(i%2){
			sum+=t*ans[1][i];
			t--;
			sum+=t*ans[0][i];
			t--;
		//	printf("%lld\n",ssum-sum-tot[0][i+1]);
			ret=max(ret,ssum-sum-tot[0][i+1]);
		}
		else{
			sum+=t*ans[0][i];
			t--;
			sum+=t*ans[1][i];
			t--;
		//	printf("%lld %lld %lld\n",ssum,sum,tot[1][i+1]);
			ret=max(ret,ssum-sum-tot[1][i+1]);
		}
	}
	printf("%lld\n",ret);
}