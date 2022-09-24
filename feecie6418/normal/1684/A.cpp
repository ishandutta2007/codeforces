#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
void Solve(){
	string str;
	cin>>str;
	if(str.length()==2)cout<<str.back()<<'\n';
	else cout<<*min_element(str.begin(),str.end())<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}