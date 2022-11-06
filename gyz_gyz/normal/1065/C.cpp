#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 300000
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 1000000007
#define inf 1000000000
#define eps 1e-8
using namespace std;
int n,k,x,ans,mi,a[N],h[N];
int main(){
	scanf("%d%d",&n,&k);mi=inf;
	rep(i,1,n){
		scanf("%I64d",&a[i]);
		if(a[i]<mi)mi=a[i];
	}
	rep(i,1,n)h[a[i]-mi]++;
	dep(i,200000,0)h[i]+=h[i+1];
	dep(i,200000,1){
		if(x+h[i]>k)x=0,ans++;x+=h[i];
	}
	if(x)ans++;
	printf("%d\n",ans);
}