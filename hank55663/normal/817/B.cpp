#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pli pair<LL,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){	
	int N;
	scanf("%d",&N);
	int a[100005];
	for(int i=0;i<N;i++)
	scanf("%d",&a[i]);
	sort(a,a+N);
	int m=1,n=1;
	for(int i=3;i<N;i++){
		if(a[i]==a[2])
		m++;
		else
		break;
	}
	if(a[1]==a[2])
	m++,n++;
	if(a[0]==a[2])
	m++,n++;
	LL ans=1;
	for(int i=0;i<n;i++)
	ans*=(m-i);
	for(int i=n;i>1;i--)
	ans/=i;
	printf("%I64d\n",ans);
}