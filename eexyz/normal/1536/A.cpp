#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define pb push_back
#define ll long long
#define pn cout<<"NO\n"
#define py cout<<"YES\n" 
int T,i,j,n,k,fl,a[N],mx,x,y,v;
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		fl=0;
		cin>>n;for(i=1;i<=n;++i)cin>>a[i],fl|=(a[i]<0);
		if(fl)pn;
		else{
			py;mx=0;
			for(i=1;i<=n;++i)mx=max(mx,a[i]);
			cout<<mx+1<<"\n";
			for(i=0;i<=mx;++i)cout<<i<<" ";
			cout<<"\n";
		}
	}
}