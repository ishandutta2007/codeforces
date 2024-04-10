#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
#define int long long
int n,m;
inline int Pow(int a,int b,int ans=1){
	for(;b;b>>=1,a=a*a%Mod) if(b&1) ans=ans*a%Mod;
	return ans;
}
signed main(){
	cin>>n>>m;
	cout<<Pow(2,n+m); 
	return 0;
}