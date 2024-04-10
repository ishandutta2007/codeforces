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
	LL tot=0;
	vector<int> v;
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		tot+=x;
		v.pb(x-y);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		if(tot<=m){
			printf("%d\n",i);
			return 0;
		}
		tot-=v[i];
	}
	if(tot<=m){
		printf("%d\n",n);
		return 0;
	}
	printf("-1\n");
}