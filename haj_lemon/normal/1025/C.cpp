#include<bits/stdc++.h>
using namespace std;
string s;
int l,f[100010],g[100010],ans;
int main(){
	cin>>s;l=s.length();f[l-1]=1;
	for (int i=l-2;i>=0;i--){
		if(s[i]!=s[i+1])f[i]=f[i+1]+1;else f[i]=1;
	}
	if (s[0]!=s[l-1])g[l-1]=f[0]+1;else g[l-1]=1;
	for (int i=l-2;i>=0;i--){
		if(s[i]!=s[i+1])g[i]=g[i+1]+1;else g[i]=1;
	}
	for (int i=0;i<l;i++) ans=max(ans,g[i]);
	cout<<min(ans,l)<<endl;
	return 0;
}