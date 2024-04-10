#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	int p[50];
	for(int i=0;i<n/2;i++)
	scanf("%d",&p[i]);
	sort(p,p+n/2);
	int ans=1e9;
	int sum=0;
	for(int i=0;i<n/2;i++){
		sum+=abs(p[i]-(2*i+1));
	}
	ans=sum;
	sum=0;
	for(int i=0;i<n/2;i++){
		sum+=abs(p[i]-(2*i+2));
	}
	printf("%d\n",min(ans,sum));
}