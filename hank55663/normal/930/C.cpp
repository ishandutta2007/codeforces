#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,int>
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
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	pii p[200005];
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		p[i*2]=mp(a,0);
		p[i*2+1]=mp(b,1);
	}
	sort(p,p+2*n);
	int a[100005];
	int now=0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		while(p[now].x==i&&p[now].y==0)cnt++,now++;
		a[i]=cnt;
		while(p[now].x==i)cnt--,now++;
	//	printf("%d %d\n",a[i],now);
	}
	vector<int> v;
	v.pb(-1);
	int dp[100005];
	MEM(dp);
	for(int i=1;i<=m;i++){
		if(v.back()<=a[i])v.pb(a[i]);
		else{
			*upper_bound(v.begin(),v.end(),a[i])=a[i];
		}
		dp[i]=v.size()-1;
	}
	reverse(a+1,a+m+1);
	vector<int> v2;
	v2.pb(-1);
	int ans=0;
	for(int i=1;i<=m;i++){
		if(v2.back()<=a[i])v2.pb(a[i]);
		else{
			*upper_bound(v2.begin(),v2.end(),a[i])=a[i];
		}
		ans=max(ans,(int)(v2.size()-1+dp[m-i]));
	}
	printf("%d\n",ans);
}