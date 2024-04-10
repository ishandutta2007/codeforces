#include<bits/stdc++.h>
using namespace std;
#define N 300020
typedef long long ll;
int n,Q,s[N];
string a;
vector<int> p[N<<2];
const int B=600005;
void Solve(){
	cin>>n>>Q;
	cin>>a;
	a=' '+a;
	for(int i=B-2*n;i<=B+2*n;++i)p[i].clear();
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+((i&1)^(a[i]=='+')?-1:1);
	}
	for(int i=1;i<=n;++i){
		p[s[i]+s[i-1]+B].push_back(i);
	}
	while(Q--){
		int l,r;
		cin>>l>>r;
		if(s[r]-s[l-1]==0){
			cout<<0<<endl;
			continue;
		}
		bool flag=false;
		if((r-l)&1){
			++l;flag=true;
		}
		int x=s[r]+s[l-1]+B;
		int u=*lower_bound(p[x].begin(),p[x].end(),l);
		if(flag){
			cout<<2<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}