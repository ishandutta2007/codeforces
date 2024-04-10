#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	vector<pair<pii,int> > v;
	char c[1005][1005];
	for(int i=0;i<n;i++)
		scanf("%s",c[i]);
	int num[1005][1005];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			num[i][j]=10000;
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<m;j++){
			if(c[i][j]=='.')
				sum=0;
			num[i][j]=min(num[i][j],sum);
			if(c[i][j]=='*')
				sum++;
		}
		sum=0;
		for(int j=m-1;j>=0;j--){
			if(c[i][j]=='.')
				sum=0;
			num[i][j]=min(num[i][j],sum);
			if(c[i][j]=='*')
				sum++;
		}
	}
	for(int j=0;j<m;j++){
		int sum=0;
		for(int i=0;i<n;i++){
			if(c[i][j]=='.')
				sum=0;
			num[i][j]=min(num[i][j],sum);
			if(c[i][j]=='*')
				sum++;
		}
		sum=0;
		for(int i=n-1;i>=0;i--){
			if(c[i][j]=='.')
				sum=0;
			num[i][j]=min(num[i][j],sum);
			if(c[i][j]=='*')
				sum++;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(num[i][j]){
				v.pb(mp(mp(i+1,j+1),num[i][j]));
			}
		}
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<m;j++){
			if(sum){
				c[i][j]='.';
				sum--;
			}
			if(num[i][j]){
				c[i][j]='.';
				sum=max(sum,num[i][j]);
			}
		}
		sum=0;
		for(int j=m-1;j>=0;j--){
			if(sum){
				c[i][j]='.';
				sum--;
			}
			if(num[i][j]){
				c[i][j]='.';
				sum=max(sum,num[i][j]);
			}
		}
	}
	for(int j=0;j<m;j++){
		int sum=0;
		for(int i=0;i<n;i++){
			if(sum){
				c[i][j]='.';
				sum--;
			}
			if(num[i][j]){
				c[i][j]='.';
				sum=max(sum,num[i][j]);
			}
		}
		sum=0;
		for(int i=n-1;i>=0;i--){
			if(sum){
				c[i][j]='.';
				sum--;
			}
			if(num[i][j]){
				c[i][j]='.';
				sum=max(sum,num[i][j]);
			}
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(c[i][j]=='*'){
				printf("-1\n");
				return 0;
			}
		}
	printf("%d\n",v.size());
	for(auto it:v)
		printf("%d %d %d\n",it.x.x,it.x.y,it.y);
}