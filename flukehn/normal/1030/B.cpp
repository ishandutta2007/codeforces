#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	//int T;cin>>T;
	int n,d,m;
	while(cin>>n>>d>>m){
		for(int i=0;i<m;++i){
			int x,y;
			cin>>x>>y;
			if(x+y>=d&&x+y<=2*n-d&&y-x>=-d&&y-x<=d)puts("YES");
			else puts("NO");
		}
	}
}