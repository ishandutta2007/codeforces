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
int visit[100005];
vector<vector<int> > ans;
vector<int> temp;
pii a[100005];
void dfs(int i,int first){
	//printf("%d %d\n",i,first);
	if(i==first)
	return;
	if(first==-1)
	first=i;
	visit[i]=1;
	temp.pb(i);
	dfs(a[i].y,first);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int b;
		scanf("%d",&b);
		a[i]=mp(b,i);
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		temp.clear();
		if(!visit[i]){
			dfs(i,-1);
//			printf("\n");
			ans.pb(temp);
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i].size());
		for(int j=0;j<ans[i].size();j++)
		printf(" %d",ans[i][j]+1);
		printf("\n"); 
	}
}
/*
14%20,15#17
20,14-18
1#5,11,4%10,14-18,20,21
11,21,20,14-18,4%10,1#5

*/