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
set<int> v[200005];
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	pii p[200005];
	int degree[200005];
	MEM(degree);
	int in[200005];
	fill(in,in+200005,1);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].insert(b);
		v[b].insert(a);
		degree[a]++;
		degree[b]++;
		p[i]=mp(a,b);
	}
	queue<int> q;
	vector<int> ans;
	int cnt=n;
	for(int i=1;i<=n;i++){
		if(degree[i]<k){
			q.push(i);
			in[i]=0;
			cnt--;
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto it:v[x]){
			if(in[it]&&--degree[it]<k){
				q.push(it);
				in[it]=0;
				cnt--;
			}
		}
	}
	ans.pb(cnt);
	reverse(p,p+m);
	for(int i=0;i<m;i++){
		if(in[p[i].x]&&in[p[i].y]){
			v[p[i].x].erase(p[i].y);
			v[p[i].y].erase(p[i].x);
			if(--degree[p[i].x]<k){
				q.push(p[i].x);
				cnt--;
				in[p[i].x]=0;
			}
			if(--degree[p[i].y]<k){
				q.push(p[i].y);
				cnt--;
				in[p[i].y]=0;
			}
			while(!q.empty()){
				int x=q.front();
				q.pop();
				for(auto it:v[x]){
					if(in[it]&&--degree[it]<k){
						q.push(it);
						in[it]=0;
						cnt--;
					}
				}
			}
		}
		ans.pb(cnt);
	}
	ans.pop_back();
	reverse(ans.begin(),ans.end());
	for(auto it:ans)
	printf("%d\n",it);
	return 0;
}