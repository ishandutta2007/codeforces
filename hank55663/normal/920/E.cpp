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
#define index Index
#define N 300005
using namespace std;
typedef long long LL;
vector<int> v[200005];
int vis[200005];
set<int> s;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i=1;i<=n;i++)
	s.insert(i);
	vector<int> ans;
	MEM(vis);
	for(int i=1;i<=n;i++){
	//	printf("%d ",vis[i]);
		if(!vis[i]){
			s.erase(i);
			int k=0;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int x=q.front();
				vis[x]=1;
				q.pop();
				k++;
				set<int> ss;
				for(auto it:v[x]){
					if(s.find(it)!=s.end())
					ss.insert(it),s.erase(it);
				}
				for(auto it:s){
					q.push(it);
				}
				s.clear();
				swap(ss,s);
			}
			ans.pb(k);
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(auto it:ans)
	printf("%d ",it);
	printf("\n");
}