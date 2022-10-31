#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=924844033;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-9;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
int p[210000];
int t[210000];

int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",p+i);
	}
	std::sort(p,p+a);
	for(int i=0;i<a;i++){
		t[lower_bound(p,p+a,p[i])-p]++;
	}
	std::sort(t,t+a);
	int ret=0;
	for(int i=1;i<=a;i++){
		int at=0;
		int cur=0;
		int nx=i;
		while(at<a){
			int to=lower_bound(t+at,t+a,nx)-t;
			if(to==a)break;
			cur+=nx;
			at=to+1;
			nx*=2;
		}
		ret=max(ret,cur);
	}
	printf("%d\n",ret);
}