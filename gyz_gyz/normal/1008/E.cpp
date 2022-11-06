#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define gc getchar()
#define N 200010
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
ll n,a,b,t1,t2;int x,u;
int main(){
	scanf("%I64d",&n);a=b=u=1;
	for(;;){
		printf("%I64d %I64d\n",a+t1,b+t2);
		fflush(stdout);scanf("%d",&x);if(!x)return 0;
		if(x==1){a+=t1;
			if(t1){
				t1*=2;if(a+t1>n)t1=n-a;	
			}else t1=1;
		}
		if(x==2){b+=t2;
			if(t2){
				t2*=2;if(b+t2>n)t2=n-b;
			}else t2=1;
		}
		if(x==3){t1/=2;t2/=2;}
	}
}