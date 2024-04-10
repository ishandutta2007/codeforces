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
#define N 5005
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main() {
	int n;
	scanf("%d",&n);
	int a[N];
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	int l[N],r[N];
	MEM(l),MEM(r);
	for(int i=1;i<=n;i++){
		if(l[a[i]]==0){
			l[a[i]]=r[a[i]]=i;
		}
		else
		{
			r[a[i]]=i;
		}
	}
	int dp[N][N];
	int visit[N];
	for(int i=1;i<=n;i++){
		int rr=r[a[i]];
		if(l[a[i]]<i)
		continue;
		MEM(visit);
		int aa=a[i];
		visit[a[i]]=1;
		for(int j=i;j<=n;j++){
			if(!visit[a[j]]){
				visit[a[j]]=1;
				aa=aa^a[j];
			}
			rr=max(rr,r[a[j]]);
			if(l[a[j]]<i)
			break;
			if(rr==j){
				dp[i][j]=aa;
		//		printf("%d %d %d\n",i,j,aa);
			}
		}
	}
	int ans[N];
	ans[0]=0;
	for(int i=1;i<=n;i++){
		ans[i]=ans[i-1]; 
		for(int j=i;j>0;j--){
			ans[i]=max(ans[i],dp[j][i]+ans[j-1]);
		}
	}
	printf("%d\n",ans[n]);
    return 0;
}