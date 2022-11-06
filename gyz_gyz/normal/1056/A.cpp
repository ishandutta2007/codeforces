#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 300
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){int m,x;
		scanf("%d",&m);
		rep(j,1,m){
			scanf("%d",&x);a[x]++;
		}
	}
	rep(i,1,100)if(a[i]==n)printf("%d ",i);
}