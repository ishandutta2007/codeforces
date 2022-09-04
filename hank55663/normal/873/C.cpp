#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
const int inf=1000000000;
#define MAXN 10000
int main() {
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int a[105][105];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	int sc=0,re=0;
	for(int i=0;i<m;i++){
		int sum=0,res=0,sk=0;
		for(int j=0;j<n;j++){
			int tot=0;
			if(a[j][i]==1){
				for(int jj=j;jj<j+k&&jj<n;jj++){
					tot+=a[jj][i];
				}
				if(tot>sum){
					sum=tot;
					res=sk;
				}
				sk++;
			} 
		}
		sc+=sum,re+=res; 
	}
	printf("%d %d\n",sc,re);
}