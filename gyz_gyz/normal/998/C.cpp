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
#define N 1000000
#define ll long long
#define inf 1000000000
#define mo 1000000007
#define eps 1e-6
using namespace std;
int n,p1,p2;char c[N];ll ans;
int main(){
	scanf("%d%d%d",&n,&p1,&p2);scanf("%s",c+1);
	rep(i,1,n)if((c[i]=='0')&&(c[i]!=c[i-1]))ans++;
	if((p1>p2)||(ans<2))printf("%I64d",ans*p2);
	else printf("%I64d",(ans-1)*p1+p2);
}