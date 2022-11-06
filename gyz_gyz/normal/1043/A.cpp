#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define ll long long
#define N 400000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int n,x,tot,p;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&x);tot+=x;p=max(p,x);
	}
	printf("%d\n",max(p,tot*2/n+1));
}