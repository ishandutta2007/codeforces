#include<bits/stdc++.h>
#define N 2000005
using namespace std;
int f1,f2,fl,n,c[N],i,g[N],x[N],y[N],ee;
int main(){
	cin>>n;
	cout<<"YES\n";
	for(i=1;i<=n;++i){
		cin>>x[i]>>y[i]>>f1>>f2;
		x[i]+=1000000000;y[i]+=1000000000;
		cout<<((x[i]&1)<<1|(y[i]&1))+1<<"\n";
	}
}