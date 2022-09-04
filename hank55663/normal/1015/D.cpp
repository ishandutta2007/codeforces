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
int main(){
	LL n,k,s;
	scanf("%lld %lld %lld",&n,&k,&s);
	if(k*(n-1)<s||k>s){
		printf("NO\n");
		return 0;
	}
	LL now=n-2,tag=1;
	vector<LL> v;
	s-=k;
	for(int i=0;i<k;i++){
		now=min(now,s);
		v.pb((now+1)*tag);
		s-=now;
		tag*=-1;
	}
	printf("YES\n");
	LL a=1;
	for(auto it:v)
	{
		a+=it;
		printf("%lld ",a);
	}
}