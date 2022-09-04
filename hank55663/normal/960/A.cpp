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
	char C[5005];
	scanf("%s",C);
	int a=0,b=0,c=0;
	int enda=0,endb=0;
	for(int i=0;C[i]!=0;i++){
		if(C[i]=='a'){
			if(enda)
			{
				printf("NO\n");
				return 0;
			}
			a++;
		}
		else if(C[i]=='b'){
			enda=1;
			if(endb){
				printf("NO\n");
				return 0;
			}
			b++;
		}
		else if(C[i]=='c'){
			endb=1;
			c++;
		}
	}
	if(a==0||b==0)
	printf("NO\n");
	else if(c==a||c==b)
	printf("YES\n");
	else
	printf("NO\n");
}