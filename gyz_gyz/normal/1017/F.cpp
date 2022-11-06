#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(unsigned int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
unsigned int n,ans,A,B,C,D,x,y;int tot;
bitset<100000000>v;
int main(){
	scanf("%d%d%d%d%d",&n,&A,&B,&C,&D);
	x=A*8+B*4+C*2+D;y=2;
	for(;;){
		ans+=n/y*x;
		if(y*2>n)break;y=y*2;
	}
	x=A*27+B*9+C*3+D;y=3;
	for(;;){
		ans+=n/y*x;
		if(y*3>n)break;y=y*3;
	}
	rep(i,5,n)if((i%2)&&(i%3)&&(!v[i/3])){
		rep(j,5,n/i)if((j%2)&&(j%3))v[i*j/3]=1;
		x=A*i*i*i+B*i*i+C*i+D;y=i;
		for(;;){
			ans+=n/y*x;
			if(n/y<i)break;y=y*i;
		}
	}
	printf("%u\n",ans);
}