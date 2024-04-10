#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 300005
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
//#include<bits/stdc++.h>
//using namespace std;
int main(){
	int n,k;
	int a[105];
	scanf("%d %d",&n,&k);
	int sum=0;
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]),sum+=a[i];
	int now=0;
	while((now+n)*k-(now+n)/2>sum){
		sum+=k;
		now++;
	} 
	printf("%d\n",now);
}