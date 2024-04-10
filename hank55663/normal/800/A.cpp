//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	int n;
	LL p;
	scanf("%d %I64d",&n,&p);
	LL Sum=0;
	pll pp[100005];
	for(int i=0;i<n;i++){
		LL a,b;
		scanf("%I64d %I64d",&a,&b);
		Sum+=a;
		pp[i]=mp(a,b);
	}
	if(Sum<=p){
	printf("-1\n");
		return 0;
	}
	double Max=1e18,Min=0;
	while(Max-Min>1e-7){
		double mid=(Max+Min)/2;
		double sum=0;
		for(int i=0;i<n;i++){
			if((double)pp[i].y<pp[i].x*mid){
				sum+=(pp[i].x*mid-pp[i].y)/mid;
			}
		}
		if(sum>p)
		Max=mid;
		else
		Min=mid;
	}
	printf("%.8lf\n",Min);
}

/*90 110
180 220
270 330
360 440
450 550
540 660
630 770
*/