/*#include<bits/stdc++.h>
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
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;*/
#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int a[205][205];
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++)
			scanf("%d",&a[i][j]);
	}
	int ansr[205];
	int ansc[205];
	fill(ansr,ansr+205,0);
	fill(ansc,ansc+205,0);
	for(int k=0;k<=m;k++){
		for(int j =0;j<m;j++){
			if(j<k){
				if(a[0][j]==1){
					ansc[j]^=1;
					for(int i=0;i<n;i++)
						a[i][j]^=1;
				}
			}
			else{
				if(a[0][j]==0){
					ansc[j]^=1;
					for(int i =0;i<n;i++)
						a[i][j]^=1;
				}
			}
		}
		int check=0;
		for(int i = 0;i<n;i++){
			int temp=0;
			for(int j =0;j<m;j++){
				if(a[i][j]!=a[i][0]){
					temp=1;
					//check=1;
				}
			}
			if(a[i][0]!=check){
				ansr[i]^=1;
				for(int j =0;j<m;j++){
					a[i][j]^=1;
				}
			}
			check|=temp;
		}
		vector<int> v;
		v.pb(0);
		int ok=1;
		for(int i = 0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]<v.back()){
					ok=0;//printf("NO\n");
					//return 0;
				}
				v.pb(a[i][j]);
			}
		}
	/*	for(auto it:v)
		printf("%d ",it);
		printf("\n");*/
		if(ok)
		break;
		if(k==m&&!ok){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(int i =0;i<n;i++){
		printf("%d",ansr[i]);
	}
	printf("\n");
	for(int i =0;i<m;i++){
		printf("%d",ansc[i]);
	}
	printf("\n");
	return 0;
}
/*
0 1
1 1
2 1
3 2
4 2
5 2

6 3

*/
/*
 9 10 11
*/