#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 400000
#define ll long long
#define mo 2147483647
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,x,ans,a[N];bool v[5000];
int gcd(int x,int y){
	if(!x)return y;return gcd(y%x,x);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);x=a[1];
	rep(i,2,n)x=gcd(x,a[i]);
	rep(i,1,n)a[i]/=x;
	rep(i,2,4000)if(!v[i]){
		rep(j,2,4000/i)v[i*j]=1;x=0;
		rep(j,1,n){
			if(!(a[j]%i))x++;
			while(!(a[j]%i))a[j]/=i;
		}
		if(x>ans)ans=x;
	}x=0;
	sort(a+1,a+n+1);
	rep(i,1,n)if(a[i]==a[i-1])x++;else{
		if((a[i-1]>1)&&(x>ans))ans=x;x=1;
	}
	if((a[n]>1)&&(x>ans))ans=x;
	if(!ans)printf("-1");else printf("%d",n-ans);
}