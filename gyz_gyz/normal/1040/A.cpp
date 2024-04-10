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
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 300000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define n2 500000004
#define eps 1e-8
using namespace std;
int n,ans,p[3],a[30];
int main(){
	 scanf("%d%d%d",&n,&p[0],&p[1]);p[2]=min(p[0],p[1]);
	 rep(i,1,n)scanf("%d",&a[i]);
	 if((n&1)&&(a[n/2+1]==2))ans+=p[2];
	 rep(i,1,n/2)if(a[i]==2){
		if(a[n-i+1]==2)ans+=p[2]*2;
		else ans+=p[a[n-i+1]];
	}else{
		if(a[n-i+1]==2)ans+=p[a[i]];
		else if(a[n-i+1]!=a[i]){
			printf("-1");return 0;
		}
	}
	printf("%d",ans);
}