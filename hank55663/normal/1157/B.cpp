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
	int n;
	scanf("%d",&n);
	char c[200005];
	scanf("%s",c);
	int f[10];
	for(int i = 1;i<=9;i++)
		scanf("%d",&f[i]);
	for(int i = 0;c[i]!=0;i++){
		if(f[c[i]-'0']+'0'>c[i]){
			for(int j =i;c[j]!=0;j++){
				if(f[c[j]-'0']+'0'>=c[j]){
					c[j]=f[c[j]-'0']+'0';
				}
				else{
					break;
				}
			}
			break;
		}
	}
	printf("%s\n",c);
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