#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
char a[N];
int n,i,j,x,y,b,q,c,is[N],T,l,r,s,fl;
int check(int x){
	for(i=2;i<x;++i){
		if(x%i==0)return 1;
	}
	return 0;
}
int m,vis[1000005];
int main(){
	cin>>n>>m;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			cin>>a[i*m-m+j];
	for(i=1;i<n;++i){
		for(j=1;j<m;++j){
			if(a[i*m-m+j+1]=='X'&&a[i*m+j]=='X'){
				is[j]=1;
			}
		}
	}
	for(i=1;i<m;++i)is[i]+=is[i-1];
	cin>>q;
	while(q--){
		cin>>x>>y;
		if(is[y-1]>is[x-1]){
			cout<<"NO\n";
		}
		else cout<<"YES\n";
	}
}