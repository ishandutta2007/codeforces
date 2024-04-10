#include<bits/stdc++.h>
using namespace std;
const int N=3e5+2;
long long ans;
int T,n,q,i,x,y,a[N];
int f(int x){return max(0,a[x]-a[x-1]);}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&q),ans=a[n+1]=0;
		for(int i=1;i<=n;i++)scanf("%d",a+i),ans+=f(i);
		while(cout<<ans<<'\n',q--){
			scanf("%d%d",&x,&y);
			ans-=f(x)+f(x+1)+(x+1<y)*f(y)+(x<y)*f(y+1);
			swap(a[x],a[y]);
			ans+=f(x)+f(x+1)+(x+1<y)*f(y)+(x<y)*f(y+1);
		}
	}
	return 0;
}