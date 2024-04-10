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
	int n;
	scanf("%d",&n);
	char c[4][105][105];
	for(int i=0;i<4;i++){
		for(int j=0;j<n;j++)
			scanf("%s",c[i][j]);
	}
	int a[4]={0,1,2,3};
	int Min=1e9;
	do{
		char chess[205][205];
		for(int i=0;i<2*n;i++)
			for(int j=0;j<2*n;j++){
				chess[i][j]=c[a[i/n*2+j/n]][i%n][j%n];
			}
		int ans=0;
		for(int i=0;i<2*n;i++)
			for(int j=0;j<2*n;j++){
				if((i+j)%2==0){
					if(chess[i][j]=='1')
					ans++;
				}
				else{
					if(chess[i][j]=='0')
					ans++;
				}
			}
		Min=min(Min,ans);
	}while(next_permutation(a,a+4));
	printf("%d\n",Min);
}