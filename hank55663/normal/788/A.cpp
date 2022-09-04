#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	int a[100000];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int dif[100000];
	for(int i=0;i<n-1;i++)
	dif[i]=abs(a[i+1]-a[i]);
	LL ans=0,Min=0;
	LL sum=0;
	for(int i=0;i<n-1;i++){
		if(i%2==0)
		sum+=dif[i];
		else
		sum-=dif[i];
		if(i%2==1)
		Min=min(sum,Min);
		ans=max(sum-Min,ans);
	}
	Min=0,sum=0;
	for(int i=1;i<n-1;i++){
		if(i%2==1)
		sum+=dif[i];
		else
		sum-=dif[i];
		if(i%2==0)
		Min=min(sum,Min);
		ans=max(sum-Min,ans);
	}
	printf("%I64d\n",ans);
}/**/