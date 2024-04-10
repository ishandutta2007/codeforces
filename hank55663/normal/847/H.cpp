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
int main(){
	int n;
	scanf("%d",&n);
	int a[100005];
	pll in[100005];
	pll de[100005];
	MEM(in);
	MEM(de);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	LL last=0,now=0;
	for(int i=1;i<=n;i++){
		if(a[i]>last)
			last=a[i];
		else{
			now+=last-a[i]+1;
			last++;
		}
		in[i]=mp(now,last);
	}
	last=0,now=0;
	for(int i=n;i>=1;i--){
		if(a[i]>last)
		last=a[i];
		else {
			now+=last-a[i]+1;
			last++;
		}
		de[i]=mp(now,last);
	}
	LL ans=1e18;
	for(int i=1;i<=n;i++){
//		printf("%I64d %I64d\n",de[i],in[i]);
		LL add=max(de[i+1].y,in[i-1].y)+1-a[i];
		if(add<0)
		add=0;
		//printf("%I64d %I64d %I64d\n",de[i+1].x,in[i-1].x,add);
		ans=min(ans,(LL)de[i+1].x+in[i-1].x+add);
	}
	printf("%I64d\n",ans);
}