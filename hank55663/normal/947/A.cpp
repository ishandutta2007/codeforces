#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int isprime[1000005];
vector<int> prime;
void find(){
	MEM(isprime);
	for(int i=2;i<1000005;i++){
		if(!isprime[i]){
			for(int j=i;j<1000005;j+=i)
			isprime[j]=i;
			prime.pb(i);
		}
	}
}
int main(){
	int x;
	scanf("%d",&x);
	find();
	int ans=1e7;
	for(int i=1;i<isprime[x];i++){
		int y=x-i;
		//printf("%d\n",y);
		if(isprime[y]!=y)
		ans=min(y-isprime[y]+1,ans);
		ans=min(y,ans);
	}
	printf("%d\n",ans);
}