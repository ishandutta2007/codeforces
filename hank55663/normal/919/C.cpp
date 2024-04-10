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
#define N 200005
using namespace std;
typedef long long LL;
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	char c[2005][2005];
	for(int i=0;i<n;i++){
		scanf("%s",c[i]);
	} 
	int ans=0;
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<m;j++){
			if(c[i][j]=='.')
			sum++;
			else{
				ans+=max(0,sum-k+1);
				sum=0;
			}
		}
		ans+=max(0,sum-k+1);
	}
	for(int i=0;i<m;i++){
		int sum=0;
		for(int j=0;j<n;j++){
			if(c[j][i]=='.')
			sum++;
			else{
				ans+=max(0,sum-k+1);
				sum=0;
			}
		}
		ans+=max(0,sum-k+1);
	}
	if(k==1)
	ans/=2;
	printf("%d\n",ans);
}