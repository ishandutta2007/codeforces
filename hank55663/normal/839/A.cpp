#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
using namespace std;
typedef long long LL;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int now=0;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(a>=8){
			k-=8;
			a-=8;
			now+=a;
		}
		else{
			k-=a;
			k-=now;
			if(now+a>=8){
				now=now-8+a;;
				k+=now;
			}
			else{
				now=0;
			}
		}
		if(k<=0){
			printf("%d\n",i+1);
			return 0;
		}
	}
	printf("-1\n");
}