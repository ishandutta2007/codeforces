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
	int n,k;
	scanf("%d %d",&n,&k);
	int cnt[16];
	MEM(cnt);
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			sum<<=1;
			sum+=x;
		}
		cnt[sum]++;
	}
	if(cnt[0]){
		printf("YES\n");
		return 0;
	}
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<(1<<k);j++){
			if(!(i&j)&&cnt[i]&&cnt[j]){
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}