#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
	int n;
	cin>>n;
	for(int i=max(n-100,1);i<=n;i++){
		int ti=i,s=0;
		while(ti)s+=ti%10,ti/=10;
		if(i+s==n)v.push_back(i);
	}
	cout<<v.size()<<'\n';
	for(int i:v)cout<<i<<' ';
}