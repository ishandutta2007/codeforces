#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,sx,sy,tx,ty;
inline int Dis(int s,int t,int n){
	if(t>=s)return t-s;
	return n-t+n-s;
}
void Solve(){
	cin>>n>>m>>sx>>sy>>tx>>ty;
	cout<<min(Dis(sx,tx,n),Dis(sy,ty,m))<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}