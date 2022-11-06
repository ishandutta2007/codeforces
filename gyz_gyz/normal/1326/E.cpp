#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
struct po{
	int in=0,out=0;
	friend po operator +(const po&a,const po&b){po c;
		if(a.out>b.in)c.in=a.in,c.out=b.out+a.out-b.in;
		else c.in=a.in+b.in-a.out,c.out=b.out;
		return c;
	}
}a[N*4];
int t[N];
void f(int x,int y,bool ty,int l,int r){
	if(l==r){
		if(ty){
			if(a[x].in)--a[x].in;else ++a[x].out;
		}else{
			if(a[x].out)--a[x].out;else ++a[x].in;
		}return;
	}int m=(l+r)>>1;
	if(y<=m)f(x<<1,y,ty,l,m);else f(x<<1|1,y,ty,m+1,r);
	a[x]=a[x<<1]+a[x<<1|1];
}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);t[x]=i;
	}int nw=n;
	f(1,t[n],1,1,n);
	rep(i,1,n){int x;
		while(!a[1].out)f(1,t[--nw],1,1,n);
		printf("%d%c",nw,i==n?'\n':' ');
		scanf("%d",&x);f(1,x,0,1,n);
	}
}