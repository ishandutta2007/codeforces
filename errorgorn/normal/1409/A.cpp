#include <bits/stdc++.h>
using namespace std;

#define rep(x,s,e) for(auto x=s;x!=e;x++)

int main(){
	int TC;
	cin>>TC;
	while (TC--){
		int a,b;
		cin>>a>>b;
		
		cout<<(int)ceil(abs(a-b)/10.0)<<endl;
	}
}