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
	int ans[105][105];
	MEM(ans);
	int a[105];
	int b[105];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int j=0;j<m;j++)
		scanf("%d",&b[j]);
	for(int k=30;k>=0;k--){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				ans[i][j]<<=1;
		for(int i=0;i<n;i++){
			if((1<<k)&a[i])
			for(int j=0;j<m;j++){
				if((1<<k)&b[j]){
					ans[i][j]++;
					a[i]-=(1<<k);
					b[j]-=(1<<k);
					break;
				}
			}
		}
		for(int i=0;i<n;i++){
			if((1<<k)&a[i]){
				int find=0;
					for(int j=i+1;j<n;j++){
						if((1<<k)&a[j]){
							ans[i][0]++;
							ans[j][0]++;
							a[i]-=(1<<k);
							a[j]-=(1<<k);
							find=1;
							break;
						}
					}
				if(!find){
					printf("NO\n");
					return 0;
				}
			}
		}
		for(int i=0;i<m;i++){
			if((1<<k)&b[i]){
				int find=0;
					for(int j=i+1;j<m;j++){
						if((1<<k)&b[j]){
							ans[0][i]++;
							ans[0][j]++;
							b[i]-=(1<<k);
							b[j]-=(1<<k);
							find=1;
							break;
						}
					}
				if(!find){
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	printf("YES\n");
	for(int i=0;i<n;i++,printf("\n"))
		for(int j=0;j<m;j++)
			printf("%d ",ans[i][j]);
}