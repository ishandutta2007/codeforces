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
//#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
vector<int> v[1000005];
int visit[1000005];
int N;
int have[1000005];
void dfs(int n){
	visit[n]=1;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(!visit[*it]){
			dfs(*it);
		}
	}
}
bool check(){
	for(int i=0;i<=N;i++)
	if(!visit[i]&&have[i])
	return false;
	return true;
}
int main(){
	int m;
	scanf("%d %d",&N,&m);
	int self=0;
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		have[a]=1;
		have[b]=1;
		if(a==b)
		self++;
		else{
			v[a].pb(b);
			v[b].pb(a);
		}
	}
	for(int i=0;i<=N;i++){
		if(v[i].size()!=0){
			dfs(i);
			break;
		}
	}
	if(check()){
		LL ans=0;
		for(int i=1;i<=N;i++)
		ans+=(LL)v[i].size()*(v[i].size()-1)/2;
		ans+=(LL)self*(m-1);
		ans-=(LL)self*(self-1)/2;
		printf("%I64d\n",ans); 
	}
	else{
		printf("0\n");
	}
}/**/