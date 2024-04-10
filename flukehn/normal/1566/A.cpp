#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	int n,s;
	while(cin>>n>>s){
		int m=(n+1)/2;
		n-=m-1;
		cout<<s/n<<"\n";
	}

}