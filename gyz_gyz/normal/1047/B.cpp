#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 200000
#define ll long long
#define mo 2147483647
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,x,y,ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&x,&y);
		if(x+y>ans)ans=x+y;
	}
	printf("%d",ans);
}