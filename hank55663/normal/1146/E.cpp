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
int ok[1000005];
int main() {
	int n,q;
	scanf("%d %d",&n,&q);
	int a[100005];
	for(int i = 0;i<n;i++)
		scanf("%d",&a[i]);
	int l=-1e5-1,r=1e5;
	int op=1;
	vector<pair<char,int> > v;
	while(q--){
		char c;
		int x;
		scanf(" %c %d",&c,&x);
		v.pb(mp(c,x));
	}
	reverse(v.begin(),v.end());
	for(auto it:v){
		char c=it.x;
		int x=it.y;
		if(c=='<'){
			if(x<0){
				for(int i=-x+1;i<=1e5;i++){
					if(ok[i]==0){
						ok[i]=op;
					}
					else{
						break;
					}
				}
			}
			else{
				for(int i=x;i<=1e5;i++){
					if(ok[i]==0){
						ok[i]=op;
					}
					else{
						break;
					}
				}
				op*=-1;
			}
		}
		else{
			if(x<0){
				for(int i=-x;i<=1e5;i++){
					if(ok[i]==0){
						ok[i]=-op;
					}
					else{
						break;
					}
				}
				op*=-1;
			}
			else{
				for(int i=x+1;i<=1e5;i++){
					if(ok[i]==0){
						ok[i]=-op;
					}
					else{
						break;
					}
				}
			}
		}
	}
//	for(int i = 0;i<n;i++){
//		printf("%d ",ok[abs(a[i])]);
//	}
//	printf("\n");
	for(int i = 0;i<n;i++){
		//printf("%d ",ok[abs(a[i])]);
		if(ok[abs(a[i])]==0){
			printf("%d ",op*a[i]);
		}
		else{
			printf("%d ",ok[abs(a[i])]*abs(a[i]));
		}
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