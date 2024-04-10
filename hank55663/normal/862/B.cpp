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
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
vector<int> v[100005];
int num[2];
void dfs(int a,int color,int f){
	num[color]++;
	for(vector<int>::iterator it=v[a].begin();it!=v[a].end();it++){
		if(*it!=f)
		dfs(*it,color^1,a);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1,0,0);
	printf("%I64d\n",(LL)num[0]*num[1]-n+1);
}