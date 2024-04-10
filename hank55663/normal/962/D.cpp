#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int n;
	LL a[150005];
	int ok[150005];
	MEM(ok);
	map<LL,int> m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		while(m.find(a[i])!=m.end()){
			ok[m[a[i]]]=1;
			m.erase(a[i]);
			a[i]*=2;
		}
		m[a[i]]=i;
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(!ok[i])
		cnt++;
	}
	printf("%d\n",cnt);
	for(int i=0;i<n;i++)
	if(!ok[i])
	printf("%lld ",a[i]);
	printf("\n");
}