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
	LL sum=(1+n)*n/2;
	for(int i=2;i*i<=sum;i++){
		if(sum%i==0){
			printf("Yes\n");
			vector<int> v1,v2;
			for(int j=1;j<=n;j++){
				if(j%i==0)
				v1.pb(j);
				else
				v2.pb(j);
			}
			printf("%d",v1.size());
			for(auto it:v1)
			printf(" %d",it);
			printf("\n");
			printf("%d",v2.size());
			for(auto it:v2)
			printf(" %d",it);
			printf("\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}