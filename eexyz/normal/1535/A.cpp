#include<bits/stdc++.h>
using namespace std;
#define pf push_front
#define pb push_back
#define N 2005
#define ll long long
int i,j,k,n,T,x,y,v;
int main(){
	cin>>T;
	while(T--){
		cin>>x>>y>>i>>j;
		if(max(x,y)>min(i,j)&&max(i,j)>min(x,y))cout<<"YES\n";
		else cout<<"NO\n";
	}
}