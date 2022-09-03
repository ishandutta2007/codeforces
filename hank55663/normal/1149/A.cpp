
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	int a[200005];
	int cnt[3];
	cnt[1]=cnt[2]=0;
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	sort(a,a+n);
	int index=0;
	if(cnt[2])
		a[0]=2,cnt[2]--,index++;
	if(cnt[1])
		a[index]=1,cnt[1]--,index++;
	for(int i =index;i<n;i++){
		if(cnt[2])
			a[i]=2,cnt[2]--;
		else
			a[i]=1;
	}
	for(int i = 0;i<n;i++)
	printf("%d ",a[i]);
}