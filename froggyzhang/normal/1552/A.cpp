#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T;
string s,t;
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		int n;
		cin>>n;cin>>s;
		t=s;
		sort(t.begin(),t.end());
		int ans=0;
		for(int i=0;i<n;++i)ans+=t[i]!=s[i];
		cout<<ans<<endl;
	}
	return 0;
}