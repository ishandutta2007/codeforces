#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2e5+11;
int n;
char s[N];
void solve(){
	cin>>n;
	cin>>s;
	int n1=0;
	For(i,0,2*n)if(s[i]=='1')n1++;
	if(n1%2){
		cout<<"-1\n";
		return ;
	}
	int now=0;
	vector<int> p;
	for(int i=0;i<2*n;i+=2){
		if(s[i]!=s[i+1]){
			if(s[i]==now+'0') p.push_back(i);
			else p.push_back(i+1);
			now^=1;
		}
	}
	cout<<p.size();
	For(i,0,p.size()) cout<<" "<<p[i]+1;
	cout<<"\n";	
	for(int i=2;i<=2*n;i+=2)cout<<i<<" \n"[i==2*n];
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		solve();
	}
}