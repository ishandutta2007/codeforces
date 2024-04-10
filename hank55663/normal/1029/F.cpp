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
	LL a,b;
	scanf("%lld %lld",&a,&b);
	LL sum=a+b;
	vector<pll> v1,v2;
	for(int i=1;i<=2e7;i++){
		if(a%i==0&&a/i>=i){
			v1.pb(mp(i,a/i));
		}
		if(b%i==0&&b/i>=i){
			v2.pb(mp(i,b/i));
		}
	}
	LL ans=1e18;
	for(int i=1;i<=2e7;i++){
		if(sum%i==0&&sum/i>=i){
			for(auto it:v1){
				if(it.x<=i&&it.y<=sum/i){
					ans=min(ans,(i+sum/i)*2);
					break;
				}
			}
			for(auto it:v2){
				if(it.x<=i&&it.y<=sum/i){
					ans=min(ans,(i+sum/i)*2);
					break;
				}
			}
		}
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