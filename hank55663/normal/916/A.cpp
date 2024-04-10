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
	int x;
	int h,m;
	scanf("%d",&x);
	scanf("%d %d",&h,&m);
	for(int i=0;;i++){
		if(h%10==7||m%10==7){
			printf("%d\n",i);
			break;
		}
		m-=x;
		if(m<0)
		{
			m+=60;
			h--;
		}
		if(h<0)
		h+=24;
	}
}