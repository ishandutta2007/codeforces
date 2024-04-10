#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		long long a,b;
		cin>>a>>b;
		if(a==b){
			cout<<"0 0\n";
			continue;
		}
		if(a>b)swap(a,b);
		b-=a;
		a=min(a%b,b-a%b);
		cout<<b<<" "<<a<<"\n";
	}
}