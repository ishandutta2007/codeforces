#include<bits/stdc++.h>
using namespace std;
char s[111][111];
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	while(cin>>n>>m){
		for(int i=0;i<n;++i)cin>>s[i];
		int x=0,y=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if(s[i][j]=='*')x^=i+1,y^=j+1;
		cout<<x<<" "<<y<<"\n";
	}
}