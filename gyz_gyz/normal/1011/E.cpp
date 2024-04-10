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
int n,m,x,ans;
int gcd(int x,int y){
	if(x>y)return gcd(y,x);
	if(!x)return y;else return gcd(y%x,x);
}
int main(){
	scanf("%d%d",&n,&m);ans=m;
	rep(i,1,n){scanf("%d",&x);ans=gcd(ans,x);}
	printf("%d\n",m/ans);
	rep(i,0,m/ans-1)printf("%d ",ans*i);
}