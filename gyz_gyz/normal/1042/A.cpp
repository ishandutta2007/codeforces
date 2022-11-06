#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 262144
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,m,x,mx,tot;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",&x);
		if(x>mx)mx=x;tot+=x;
	}
	printf("%d %d\n",max(mx,(tot+m-1)/n+1),mx+m);
}