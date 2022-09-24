#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int Ceil(int x){
	int p=x/2-10;
	while(p*2<x)p++;
	return p;
}
int D2(int x){
	int p=x/2-10;
	while(p*2+2<=x)p++;
	return p;
}
void Solve(){
	int a,b,n;
	cin>>a>>b,n=a+b;
	int A=n/2,B=(n+1)/2;
	vector<int> ans;
	for(int i=0;i<=a+b;i++){
		bool flag=0;
		int mn=max({0,Ceil(a+i-B),Ceil(A+i-b)});
		int mx=min({a,i,D2(A+i-b),D2(a+i-B),A});
		if(mx>=mn)flag=1;
		mn=max({0,Ceil(a+i-A),Ceil(B+i-b)});
		mx=min({a,i,D2(B+i-b),D2(a+i-A),B});
		if(mx>=mn)flag=1;
		if(flag)ans.push_back(i);
	}
	cout<<ans.size()<<'\n';
	for(int i:ans)cout<<i<<' ';
	puts("");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}