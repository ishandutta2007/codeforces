#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200010
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 998244353
#define inf 1000000000
#define eps 1e-8
using namespace std;
int n,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);a[i]+=a[i-1];
	}
	dep(i,n,1)rep(j,0,n-i)if(a[j+i]-a[j]>100*i){
		printf("%d",i);return 0;
	}printf("0");
}