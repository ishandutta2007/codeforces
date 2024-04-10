#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<long double,null_type,less<long double>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ld long double
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
int degree[200005];
int f[200005];
int ok[200005];
int Find(int x){
	if(f[x]==x)return x;
	return f[x]=Find(f[x]);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=n;i++)
		f[i]=i;
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		degree[x]++;
		degree[y]++;
		f[Find(x)]=Find(y);
	}
	fill(ok,ok+n+1,1);
	for(int i =1;i<=n;i++){
		if(degree[i]!=2){
			ok[Find(i)]=0;
		}
	}
	int ans=0;
	for(int i =1;i<=n;i++){
		if(Find(i)==i){
			ans+=ok[i];
		}
	}
	printf("%d\n",ans);
}