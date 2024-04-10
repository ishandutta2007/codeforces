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
#define MAXD 2
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int h,m,s,t1,t2;
	scanf("%d %d %d %d %d",&h,&m,&s,&t1,&t2);
	m/=5;
	s/=5;
	int ok=1,ok1=1;
	for(int i=t1;i!=t2;i=i%12+1){
		if(i%12==h%12||i%12==m%12||i%12==s%12)
		{
			ok=0;
			break;
		}
	//	printf("%d\n",i);
	}
	for(int i=t1;i!=t2;i=(i+10)%12+1){
		 if((i-1)%12==h%12||(i-1)%12==m%12||(i-1)%12==s%12){
		 	ok1=0;
		 	break;
		 }
	//	 printf("%d\n",i);
	}
//	printf("%d %d\n",ok,ok1);
	printf("%s\n",ok||ok1?"YES":"NO");
}