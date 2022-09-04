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
	scanf("%d",&n);
	map<LL,pii> m;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		LL sum=0;
		int a[200005];
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&a[j]);
			sum+=a[j];
		}
		for(int j=1;j<=k;j++){
			if(m.find(sum-a[j])!=m.end()&&m[sum-a[j]].x!=i){
				printf("YES\n");
				printf("%d %d\n",m[sum-a[j]].x,m[sum-a[j]].y);
				printf("%d %d\n",i,j);
				return 0;
			}
			else{
				m[sum-a[j]]=mp(i,j);
			}
		}
	}
	printf("NO\n");
}