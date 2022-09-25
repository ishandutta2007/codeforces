#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rnd(time(0));
int u,v,p;
vector<int> Solve(int x){
	while(true){
		int a=rnd()%(p-1)+1,b=1LL*a*x%p;
		int cnt=0;
		vector<int> A;
		while(b&&cnt<=80){
			if(a>b){
				swap(a,b),A.push_back(3),++cnt;
			}
			else{
				while(cnt<=80&&a<=b){
					b-=a;
					A.push_back(2);
					++cnt;
				}
			}
		}
		if(!b)return A;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>u>>v>>p;
	auto A=Solve(u);
	auto B=Solve(v);
	cout<<A.size()+B.size()<<'\n';
	for(auto x:A){
		cout<<x<<' ';
	}
	reverse(B.begin(),B.end());
	for(auto x:B){
		if(x<3)cout<<3-x<<' ';
		else cout<<x<<' ';
	}
	return 0;
}