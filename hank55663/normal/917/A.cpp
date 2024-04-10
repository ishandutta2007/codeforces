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
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	char c[5005];
	scanf("%s",c);
	int cnt=0;
	for(int i=1;c[i]!=0;i++){
		int Max=0,Min=0; 
		for(int j=i;j>=0;j--){
			if(c[j]==')')
			Max++,Min++;
			else if(c[j]=='(')
			Max--,Min--;
			else
			Max++,Min--;
			if(Max<0)
			break;
			if(Min<0){
				Min=Max&1;
			}
			if(Min==0)
			cnt++;
		//	printf("%d %d\n",x,h);
		}
	//	printf("%d\n",cnt);
	}
	printf("%d\n",cnt);
}