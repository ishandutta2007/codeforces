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
//#define size Size
using namespace std;
typedef long long LL;
int main(){
	LL last=1e9;
	int n,l;
	scanf("%d %d",&n,&l);
	LL a[33];
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		a[i]=min(a[i],last*2);
		last=a[i];
	} 
	for(int i=n;i<=30;i++){
		a[i]=a[i-1]*2;
	}
	int cnt[35];
	for(int i=0;i<30;i++){
		cnt[i]=l%2;
		l>>=1;
	}
	LL ans=0;
	for(int i=0;i<30;i++){
		ans=min(ans,a[i]);
		if(cnt[i]){
			ans+=a[i];
		}
	}
	printf("%I64d\n",ans);
}