#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n;
ll a[N];
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cin>>s;
	s=' '+s;
	ll E=0,G=0,ans=0;
	bool w=false;
	for(int i=1;i<=n;++i){
		if(s[i]=='G')ans+=5*a[i],G+=2*a[i],E+=a[i];
		else if(s[i]=='W')ans+=3*a[i],E+=a[i],w=true;
		else{
			E-=a[i],ans+=a[i];
			if(E<0){
				ans+=(w?3:5)*(-E);
				E=0;
			}
		}
		G=min(G,E);
	}
	cout<<ans-(5-1)*G/2-(3-1)*(E-G)/2<<'\n';
	return 0;
}