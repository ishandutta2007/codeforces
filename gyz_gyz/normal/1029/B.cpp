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
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 998244353
#define Pi acos(-1.)
#define eps 1e-8
using namespace std;
int n,x,y,nw,ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&x);
		if((i==1)||(x<=y*2))nw++;else{
			if(nw>ans)ans=nw;nw=1;
		}y=x;
	}
	if(nw>ans)ans=nw;
	printf("%d",ans);
}