/*#include<bits/stdc++.h>
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
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;*/
#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	int cnt[200005];
	fill(cnt,cnt+200005,0);
	for(int i = 1;i<=n;i++){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	int ans=0,l,r;
	int nowl=1,sum=0;
	for(int i = 1;i<=200005;i++){
		sum+=cnt[i];
		if(cnt[i]<2){
			if(sum>ans){
				ans=sum;
				l=nowl;
				r=i;
			}
			nowl=i;
			sum=cnt[i];
		}
	}
	printf("%d\n",ans);

	cnt[l]++;
	if(l!=r)
	cnt[r]++;
	for(int i=l;i<=r;i++){
		while(cnt[i]>1){
			cnt[i]--;
			printf("%d ",i);
		}
	}
	for(int i =r-1;i>l;i--)
	printf("%d ",i);
	printf("\n");
	return 0;
}
/*
0 1
1 1
2 1
3 2
4 2
5 2

6 3

*/
/*
 9 10 11
*/