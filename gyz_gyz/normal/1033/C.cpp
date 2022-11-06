#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200000
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 1000000007
#define eps 1e-18
using namespace std;
int n,a[N],p[N];bool s[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);p[a[i]]=i;
	}
	dep(i,n,1){s[p[i]]=1;
		rep(j,1,(p[i]-1)/i)if(s[p[i]-i*j])s[p[i]]=0;
		rep(j,1,(n-p[i])/i)if(s[p[i]+i*j])s[p[i]]=0;
	}
	rep(i,1,n)printf("%c",'A'+s[i]);
}