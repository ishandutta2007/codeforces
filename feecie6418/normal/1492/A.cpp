#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
void Solve(){
	ll p,a,b,c;
	cin>>p>>a>>b>>c;
	cout<<min({(a-p%(a))%(a),(b-p%(b))%(b),(c-p%(c))%(c)})<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}