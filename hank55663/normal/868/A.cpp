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
#define MAXD 2
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	char res[105];
	scanf("%s",res);
	int n;
	scanf("%d",&n);
	int ok1=0,ok2=0;
	for(int i=0;i<n;i++){
		char c[4];
		scanf("%s",c);
		if(c[0]==res[0]&&c[1]==res[1])
		ok1=1,ok2=1;
		if(c[0]==res[1])
		ok1=1;
		if(c[1]==res[0])
		ok2=1;
	//	printf("%d %d\n",ok1,ok2);
	}
	printf("%s\n",ok1&&ok2?"YES":"NO");
}