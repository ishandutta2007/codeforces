#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
using namespace std;
vector<pii> v[100005];
LL a[100005];
LL b[100005];
int vis[100005];
int vivivi[100005];
int ok=1;
LL dfs(int n){
	//printf("%d\n",n);
	vis[n]=1;
	for(vector<pii>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(vivivi[it->x]||vis[it->x])
		continue;
		LL x=dfs(it->x);
		if(x>0)
		a[n]+=x;
		else{
			LL y=x*it->y;
			if(y/(it->y)!=x||y>1e18)
			ok=0;
			a[n]+=x*it->y;
			if(a[n]>1e18)
			ok=0; 
		}
	}
	return a[n]-b[n];
}
vector<int> root;
vector<int> s;
int t;
bool dfs2(int n){
//	printf("%d\n",n);
	if(vis[n]==t){
		while(s.back()!=n){
			a[n]+=a[s.back()];
			b[n]+=b[s.back()];
			vivivi[s.back()]=n;
			/*for(vector<pii>::iterator it=v[s.back()].begin();it!=v[s.back()].end();it++)
			v[n].pb(*it);*/
			s.pop_back();
		}
		return true;
	}
	else if(vis[n]==0){
		s.pb(n);
		vis[n]=t;
		bool ok=0;
		for(vector<pii>::iterator it=v[n].begin();it!=v[n].end();it++)
		ok|=dfs2(it->x);
		if(s.back()==n)
		s.pop_back();
		return ok;
	}
	else
	return false;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	for(int j=1;j<=n;j++)
	scanf("%I64d",&b[j]);
	for(int i=2;i<=n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(mp(i,y));
	}
	root.pb(1);
	MEM(vis);
	t=1;
	for(int i=2;i<=n;i++){
		t++;
		if(dfs2(i)){
			root.pb(i);
		}
	}
	for(int i=2;i<=n;i++){
		if(vivivi[i]!=0){
			for(vector<pii>::iterator it=v[i].begin();it!=v[i].end();it++){
				v[vivivi[i]].pb(*it);
			}
		}
	}
	MEM(vis);
	for(int i=0;i<root.size();i++){
		if(dfs(root[i])<0){
			ok=0;
		}
	}
	if(ok)
	printf("YES\n");
	else
	printf("NO\n");
}