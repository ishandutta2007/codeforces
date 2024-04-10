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
string a,b,s;
int main(){
	T=read();
	while(T--){
		cin>>s;
		a='a'+s;
		b=a;
		reverse(b.begin(),b.end());
		if(a!=b){
			cout<<"YES"<<endl<<a<<endl;
			continue;
		}
		a=s+'a';
		b=a;
		reverse(b.begin(),b.end());
		if(a!=b){
			cout<<"YES"<<endl<<a<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}