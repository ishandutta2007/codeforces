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
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
vector<int> v[205];
int indegree[205];
int main(){
	int n;
	scanf("%d",&n);
	int ddo[205];
	for(int i=1;i<=n;i++)
	scanf("%d",&ddo[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&indegree[i]);
		for(int j=0;j<indegree[i];j++){
			int x;
			scanf("%d",&x);
			v[x].pb(i);
		}
	}
	queue<int> q[4];
	int ans=1e9;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=n;j++){
			if(!indegree[j])
			q[ddo[j]].push(j);
		}
		int cnt=0;
		int ind[205];
		for(int j=0;j<205;j++)
		ind[j]=indegree[j];
		int now=i;
		int res=0;
		while(cnt!=n){
			while(!q[now].empty()){
				int x=q[now].front();
				q[now].pop();
				for(vector<int>::iterator it=v[x].begin();it!=v[x].end();it++){
					if(--ind[*it]==0){
						q[ddo[*it]].push(*it);
					}
				}
				res++;
				cnt++;
			}
			if(cnt==n)
			break;
			res++;
			now=now%3+1;
		}
		ans=min(ans,res);
	}
	printf("%d\n",ans);
}