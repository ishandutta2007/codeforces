#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int T,n,k,i,j,l[N],L,R,gg,r[N],v[N],mn,mx,pos;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i)cin>>l[i]>>r[i]>>v[i];
		mn=mx=pos=1;cout<<v[1]<<"\n";
		L=l[1];R=r[1];
		for(i=2;i<=n;++i){
			L=min(L,l[i]);R=max(R,r[i]);
			if((l[i]==L&&r[i]==R)&&((l[pos]!=L||r[pos]!=R||v[pos]>v[i])))pos=i;
			gg=2e9;
			if(l[pos]==L&&r[pos]==R)gg=v[pos];
			if(l[i]==L&&(l[mn]!=L||v[mn]>v[i]))mn=i;
			if(r[i]==R&&(r[mx]!=R||v[mx]>v[i]))mx=i;
			cout<<min(gg,v[mn]+v[mx])<<"\n";
		}
	}
}