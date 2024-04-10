#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1e6+2;
int T,n,tot,a[N],d[N],t[N];
void pia(int x){if(!--d[x-a[x]])pia(x-a[x]);t[x]=0,tot--;}
int main(){
	for(scanf("%d",&T);T--;cout<<'\n'){ 
		scanf("%d",&n),tot=n;
		FOR(i,1,n)scanf("%d",a+i),d[i-a[i]]++,t[i]=1;
		FOR(i,1,n)if(!d[i]&&t[i])pia(i);
		cout<<tot<<'\n';
		FOR(i,1,n)if(d[i])cout<<i<<' ',d[i]=t[i]=0;
	}
	return 0;
}