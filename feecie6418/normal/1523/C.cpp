#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
void Solve(){
	cin>>n;
	vector<int> v;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		if(x==1)v.push_back(1);
		else {
			while(v.back()!=x-1)v.pop_back();
			v[v.size()-1]=x;
		}
		for(int j=0;j<v.size();j++)cout<<v[j]<<".\n"[j+1==v.size()];
	}
}
int main(){
	cin>>t;
	while(t--)Solve();
}