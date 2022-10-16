#include<bits/stdc++.h>
#define N 2000005
using namespace std;
int f1,f2,fl,n,c[N],i,g[N],x[N],y[N],ee;
int main(){
	cin>>n;
	for(i=1;i<n;++i){
		cin>>x[i]>>y[i];

	}
	for(i=1;i<=n;++i)cin>>c[i];
	for(i=1;i<n;++i){
		if(c[x[i]]!=c[y[i]]){
			++g[x[i]];++g[y[i]];
			f1=x[i];f2=y[i];
		}
	}
	if(!f1)return cout<<"YES\n"<<1,0;
	for(i=1;i<n;++i){
		if(c[x[i]]!=c[y[i]]&&x[i]!=f1&&y[i]!=f1)fl=1;
	}
	if(!fl)return cout<<"YES\n"<<f1,0;
	fl=0; 
	for(i=1;i<n;++i){
		if(c[x[i]]!=c[y[i]]&&x[i]!=f2&&y[i]!=f2)fl=1;
	}
	if(!fl)return cout<<"YES\n"<<f2,0;
	return cout<<"NO",0;
}