#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 2005
#define pi 3.14159265359
using namespace std;
vector<int> v[200005];
queue<int> ans;
int visit[200005];
void dfs(int n){
	visit[n]=1;
	ans.push(n);
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(!visit[*it]){
			dfs(*it);
			ans.push(n);
		}
	}
}
int main()
{	
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int ti=k;
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a); 
	}
	memset(visit,0,sizeof(visit));
	dfs(1);
	memset(visit,0,sizeof(visit));
	while(!ans.empty()){
		int b=(2*n)/k;
		if((2*n%k)!=0)
		b++;
		int a=min((int)ans.size(),b);
		printf("%d",a);
		for(int i=0;i<a;i++){
			printf(" %d",ans.front());
			visit[ans.front()]=1;
			int b=ans.front();
			ans.pop();
		}
		printf("\n");
		ti--;
	}
	while(ti){
		printf("1 1\n");
		ti--;
	}
}