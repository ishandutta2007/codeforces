#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 200000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
ll a,b,l,r,m;int x,w[N];
int main(){
	scanf("%I64d%I64d",&a,&b);
	l=0;r=70000;m=(l+r+1)/2;
	for(;l<r;m=(l+r+1)/2){x=a;
		dep(i,m,1)if(x>=i)x-=i;
		if(m*(m+1)/2-a+x<=b)l=m;else r=m-1;
	}x=0;
	dep(i,m,1)if(a>=i)w[i]=1,x++,a-=i;
	printf("%d\n",x);
	rep(i,1,m)if(w[i])printf("%d ",i);printf("\n");
	printf("%d\n",m-x);
	rep(i,1,m)if(!w[i])printf("%d ",i);
}