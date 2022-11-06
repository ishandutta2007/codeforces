#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 2000000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,d,m,x,y;
int main(){
	scanf("%d%d%d",&n,&d,&m);
	rep(i,1,m){
		scanf("%d%d",&x,&y);
		if((x+y>=d)&&(x+y<=n*2-d)&&(x-y>=-d)&&(y-x>=-d))printf("YES\n");
		else printf("NO\n");
	}
}