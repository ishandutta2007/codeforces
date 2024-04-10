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
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
using namespace std;
int main(){
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	int t[55];
	int sum=0;
	int ans=0;
	for(int i=0;i<k;i++)
	scanf("%d",&t[i]),sum+=t[i];
	sort(t,t+k);
	for(int i=0;i<=n;i++){
		if(sum*i>m)
		break;
		int temp=m-sum*i;
		int tot=i*(k+1);
		for(int j=0;j<k;j++){
			for(int l=0;l<n-i;l++){
				temp-=t[j];
				if(temp>=0)
				tot++;
				else
				break;
			}
		}
		ans=max(ans,tot);
	}
	printf("%d\n",ans);
}