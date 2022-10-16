#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define IOS ios::sync_with_stdio(0)
#define ls k<<1
#define rs k<<1|1
int T,n,m,i,j,k,x,y,a[N]; 
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n>>k;x=0;
		for(i=1;i<=n;++i)cin>>y,x=max(x,y);
		if(x==1){
			cout<<"YES\n"; 
		}
		else{
			cout<<"NO\n";
		}
	}
}