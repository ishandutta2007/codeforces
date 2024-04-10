#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define next Next
#define N 300005
using namespace std;
typedef long long LL;
vector<int> v[N];
int degree[N];
int main(){
	int n,m;
	scanf("%d %d %d",&n,&m);
	char c[N];
	scanf("%s",c);
	MEM(degree);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		degree[b]++;
	}
	int ans=0;
	for(char i='a';i<='z';i++){
		int de[N];
		int dp[N];
		MEM(dp);
		queue<int> q;
		for(int j=1;j<=n;j++){
			de[j]=degree[j];
			if(de[j]==0)
			q.push(j);
		}
		int cnt=0;
		int res=0;
		while(!q.empty()){
			int x=q.front();
			q.pop();
		//	printf("%d\n",x);
			cnt++;
			if(c[x-1]==i)
			dp[x]++;
			res=max(res,dp[x]);
			for(auto it:v[x]){
				dp[it]=max(dp[it],dp[x]);
				if(--de[it]==0){
					q.push(it);
				}
			//	printf("%d %d\n",de[it],it);
			}
		}
		if(cnt!=n)
		{
			printf("-1\n");
			return 0;
		}
	//	printf("%d\n",res);
		ans=max(ans,res);
	}
	printf("%d\n",ans);
}