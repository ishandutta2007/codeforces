#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T;
int n,m;
string s,t;
string ite(string s){
	string t=s;
	for(int i=0;i<n;++i){
		if(t[i]=='1')continue;
		int cnt=(i>0&&s[i-1]=='1')+(i<n-1&&s[i+1]=='1');
		if(cnt==1)t[i]='1';	
	}	
	return t;
}
void Solve(){
	n=read(),m=read();
	cin>>s;
	for(int i=1;i<=m;++i){
		t=ite(s);
		if(s==t)break;
		s=t;	
	}
	cout<<t<<endl;	
}
int main(){
	T=read();
	while(T--){
		Solve();	
	}
	return 0;
}