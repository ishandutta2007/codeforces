#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=1e5+11;
char s[N],t[N];
int n;
int p[26],q[26];
void solve(){
	cin>>n>>s;
	t[n]=0;
	memset(p,-1,sizeof(p));
	memset(q,-1,sizeof(q));
	For(i,0,n) {
		int c=s[i]-'a';
		if(~q[c]) {
			t[i]=q[c]+'a';
			continue;
		}
		int j;
		for(j=0;j<26;++j) {
			if(j==c||~p[j])continue;
			if(~p[c] && ~q[j]) {
				int x=c;
				int r=0;
				while(~p[x]) r+=1,x=p[x];
				if(r<25 && x==j) continue;
			}
			p[j]=c;
			q[c]=j;
			break;
		}
		t[i]=j+'a';
	}
	cout<<t<<"\n";
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}