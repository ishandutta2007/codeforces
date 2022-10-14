#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e5+1;
int T,n,a[N];
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		FOR(i,1,n)scanf("%d",a+i);
		int maxn=a[1],ans=0,k=0;
		FOR(i,2,n)ans=max(ans,maxn-a[i]),maxn=max(maxn,a[i]);
		while(ans>0)k++,ans>>=1;
		cout<<k<<'\n';
	}
	return 0;
}