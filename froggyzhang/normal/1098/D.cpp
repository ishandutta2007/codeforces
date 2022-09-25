#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
int n;
multiset<int> s[31];
ll sum[31];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--){
		char opt;
		int x;
		cin>>opt>>x;
		int z=__lg(x);
		if(opt=='+')s[z].insert(x),sum[z]+=x;
		else s[z].erase(s[z].find(x)),sum[z]-=x;
		int ans=0;
		ll now=0;
		for(int i=0;i<=30;++i){
			if(!s[i].empty())ans+=(int)s[i].size()-((*s[i].begin())>2*now);
			now+=sum[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}