#include<bits/stdc++.h>
using namespace std;
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1e6+1;
int n,k,tot,X[N],Y[N];
V solve(int l,int r){
	if(l==r)return;
	int mid=l+r>>1,len=mid-l+1;
	solve(l,mid),solve(mid+1,r);
	FOR(i,1,len)tot++,X[tot]=l+i-1,Y[tot]=mid+i;
}
int main(){
	for(cin>>n,k=1;k*2<n;k<<=1);
	solve(1,k),solve(n-k+1,n);
	cout<<tot<<'\n';
	FOR(i,1,tot)cout<<X[i]<<' '<<Y[i]<<'\n';
	return 0;
}