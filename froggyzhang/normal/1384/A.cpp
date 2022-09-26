#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
inline int read(){
	int x=0,f=1;
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
int T,n;
void Solve(){
	string a,b;
	for(int i=0;i<50;++i){
		a+='a';
	}
	cout<<a<<endl;
	for(int i=1;i<=n;++i){
		int x=read();
		b="";
		for(int j=0;j<x;++j){
			b+=a[j];
		}
		for(int j=x;j<50;++j){
			if(a[j]=='a')b+='b';
			else b+='a';
		}
		cout<<b<<endl;
		swap(a,b);
	}
}
int main(){
	T=read();
	while(T--){
		n=read();
		Solve();
	}
	return 0;
}