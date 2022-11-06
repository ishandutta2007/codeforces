#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int mo=1e9+7;
const int inf=1e9;
int a[N];char s[N];
int main(){int n;
	scanf("%d%s",&n,s+1);
	rep(i,1,n)a[i]=a[i-1]+(s[i]=='('?1:-1);
	if(a[n])return printf("0\n1 1\n"),0;
	int mi=n+1,ct=0;
	rep(i,1,n){
		if(a[i]<mi)mi=a[i],ct=1;
		else if(a[i]==mi)++ct;
	}
	int ans=ct,al=1,ar=1;
	int l=0,r=0;
	rep(i,1,n){
		if(s[i]==')')l=i;
		if(a[i]==mi)break;
	}
	dep(i,n,1){
		if(a[i]==mi)break;
		if(s[i]=='(')r=i;
	}
	if(l&&r){int nm=mi,nc=ct;
		rep(i,1,l-1)if(a[i]-2<nm)nm=a[i]-2,nc=1;
		else if(a[i]-2==nm)++nc;
		rep(i,r,n)if(a[i]-2<nm)nm=a[i]-2,nc=1;
		else if(a[i]-2==nm)++nc;
		if(nc>ans)ans=nc,al=l,ar=r;
	}l=0;r=0;
	rep(i,1,n){
		if(s[i]==')')l=i;
		if(a[i]<=mi+1)break;
	}
	dep(i,n,1){
		if(a[i]<=mi+1)break;
		if(s[i]=='(')r=i;
	}
	if(l&&r){int nm=mi,nc=ct;
		rep(i,1,l-1)if(a[i]-2<nm)nm=a[i]-2,nc=1;
		else if(a[i]-2==nm)++nc;
		rep(i,r,n)if(a[i]-2<nm)nm=a[i]-2,nc=1;
		else if(a[i]-2==nm)++nc;
		if(nc>ans)ans=nc,al=l,ar=r;
	}l=0;r=0;
	rep(i,1,n){
		if(s[i]==')')r=i;
		if(a[i]==mi){
			if(l&&r){int nm=mi,nc=ct;
				rep(j,l,r-1)if(a[j]-2<nm)nm=a[j]-2,nc=1;
				else if(a[j]-2==nm)++nc;
				if(nc>ans)ans=nc,al=l,ar=r;
			}l=r=0;
		}else if(!l&&s[i]=='(')l=i;
	}
	if(l&&r){int nm=mi,nc=ct;
		rep(j,l,r-1)if(a[j]-2<nm)nm=a[j]-2,nc=1;
		else if(a[j]-2==nm)++nc;
		if(nc>ans)ans=nc,al=l,ar=r;
	}l=r=0;
	rep(i,1,n){
		if(s[i]==')')r=i;
		if(a[i]<=mi+1){
			if(l&&r){int nm=mi,nc=ct;
				rep(j,l,r-1)if(a[j]-2<nm)nm=a[j]-2,nc=1;
				else if(a[j]-2==nm)++nc;
				if(nc>ans)ans=nc,al=l,ar=r;
			}l=r=0;
		}else if(!l&&s[i]=='(')l=i;
	}
	if(l&&r){int nm=mi,nc=ct;
		rep(j,l,r-1)if(a[j]-2<nm)nm=a[j]-2,nc=1;
		else if(a[j]-2==nm)++nc;
		if(nc>ans)ans=nc,al=l,ar=r;
	}l=r=0;
	printf("%d\n%d %d\n",ans,al,ar);
}