#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define N 5010
using namespace std;
int a[N],b[N],c[N];
int main(){int n=0,m,ans=0;
	scanf("%d",&m);
	rep(i,1,m){int x;
		scanf("%d",&x);
		if(!n||x!=a[n])a[++n]=x;
	}
	rep(i,1,n){
		rep(j,i+1,n)if(a[i]==a[j])b[j]=max(b[j],c[j+1]+1);
		dep(j,n,i)c[j]=max(c[j],max(b[j],c[j+1]));
		ans=max(ans,c[i]);
	}
	printf("%d\n",n-ans-1);
}