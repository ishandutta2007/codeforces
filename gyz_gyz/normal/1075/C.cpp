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
int n,m,tot,ans,a[N],b[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m){int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)b[++tot]=y;
	}
	a[++n]=inf;ans=tot;int x=1;
	sort(a+1,a+n+1);sort(b+1,b+tot+1);
	rep(i,1,n){
		while(x<=tot&&b[x]<a[i])x++;
		ans=min(ans,tot-x+i);
	}
	printf("%d\n",ans);
}