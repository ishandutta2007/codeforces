#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int calc(int a,int b,int c){
	return max(0,max(b,c)+1-a);
}
void Solve(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<calc(a,b,c)<<' '<<calc(b,a,c)<<' '<<calc(c,a,b)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}