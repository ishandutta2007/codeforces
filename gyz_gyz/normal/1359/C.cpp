#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=1e9;
const int mo=998244353;
int c,h,t;
double cal(double x){
	return abs((x*c+(x+1)*h)/(x*2+1)-t);
}
void sol(){
	scanf("%d%d%d",&h,&c,&t);
	if(c+h>=t*2)printf("2\n");else{
		int r=(h-t)/(2*t-c-h);
		double s1=cal(r),s2=cal(r+1);
		if(s1>s2)++r;
		printf("%d\n",r*2+1);
	}
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}