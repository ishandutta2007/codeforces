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
#define index Index
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=0;i<4;i++){
		int x;
		scanf("%d",&x);
		sum+=x;
	}
	int ans=1;
	for(int i=1;i<n;i++){
		int tot=0;
		for(int j=0;j<4;j++){
			int x;
			scanf("%d",&x);
			tot+=x;
		}
		if(tot>sum)
		ans++;
	}
	printf("%d\n",ans);
}