#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
using namespace std;
typedef long long LL;
vector<int> v[100005];
double dfs(int a,int f){
	double sum=v[a].size()-1;
	if(a==1)
	sum++;
	for(vector<int>::iterator it=v[a].begin();it!=v[a].end();it++){
		if(*it!=f){
			double add=dfs(*it,a);
			//printf("%d %.12lf\n",*it,add);
			sum+=add;
		}
	}
	if(a!=1&&v[a].size()==1)
	return 0;
	if(a!=1)
	return sum/(v[a].size()-1);
	else
	return sum/v[a].size();
}
int main(){
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	printf("%.12lf\n",dfs(1,0));
}