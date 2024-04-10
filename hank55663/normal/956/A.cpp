#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	char c[55][55];
	set<LL> s;
	for(int i=0;i<n;i++){
		scanf("%s",c[i]);
		LL ret=0;
		for(int j=0;j<m;j++){
			ret<<=1;
			if(c[i][j]=='#')
			ret++;
		}
		s.insert(ret);
	}
	vector<LL> v;
	for(auto it:s)
	v.pb(it);
	for(int i=0;i<v.size();i++)
		for(int j=i+1;j<v.size();j++)
			if(v[i]&v[j]){
				printf("No\n");
				return 0;
			}
	printf("Yes\n");
}