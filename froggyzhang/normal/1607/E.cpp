#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
string s;
void Solve(){
	cin>>n>>m;
	cin>>s;
	int x=0,y=0,lx=1,rx=n,ly=1,ry=m;
	for(auto c:s){
		if(c=='U')--x;
		if(c=='D')++x;
		if(c=='L')--y;
		if(c=='R')++y;
		int px=lx,py=ly;
		lx=max(lx,-x+1);
		ly=max(ly,-y+1);
		rx=min(rx,n-x);
		ry=min(ry,m-y);
		if(lx>rx||ly>ry){
			cout<<px<<' '<<py<<'\n';
			return;
		}
	}
	cout<<lx<<' '<<ly<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}