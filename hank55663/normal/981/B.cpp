#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define last Last
using namespace std;
typedef long long LL;
int main(){
	int n;
	map<int,int> m;
	for(int j=0;j<2;j++){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			m[a]=max(m[a],b);
		}
	}
	LL ans=0;
	for(auto it:m)
	ans+=it.y;
	printf("%lld\n",ans);
}