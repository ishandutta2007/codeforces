#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
using namespace std;
typedef long long LL;
int main()
{
	int n;
	scanf("%d",&n);
	char c[1005];
	int ans=0;
	while(scanf("%s",c)!=EOF){
		int sum=0;
		for(int i=0;c[i]!=0;i++){
			if(c[i]>='A'&&c[i]<='Z'){
				sum++;
			}
		}
		ans=max(ans,sum);
	}
	printf("%d\n",ans);
}