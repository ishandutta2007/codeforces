#include<bits/stdc++.h>
using namespace std;
#define N 233
typedef long long ll;
const ll inf=1e18+1;
int n,m;
ll k;
string L[N],R[N],ed[N];
ll f[N];
ll check(string s){
	L[0]=R[0]="0",L[1]=R[1]="1";
	f[0]=s==L[0],f[1]=s==L[1];
	int len=s.length();
	for(int i=2;i<=n;++i){
		f[i]=f[i-1]+f[i-2];
		L[i]=L[i-2],R[i]=R[i-1];
		if(L[i].length()<len){
			L[i]+=L[i-1];
			if(L[i].length()>len)L[i].resize(len);
		}
		if(R[i].length()<len){
			R[i]+=R[i-2];
			if(R[i].length()>len)R[i].resize(len);
		}
		string t=R[i-2];
		reverse(t.begin(),t.end());
		t+=L[i-1];
		for(int j=max(0,(int)R[i-2].length()-len+1);j<(int)R[i-2].length();++j){
			if(t.substr(j,len)==s)++f[i];
		}
		if(f[i]>=inf)return inf;
	}
	return f[n];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>m;
	string ans="";
	--k;
	check(string(m,'0'));
	for(int i=1;i<=(int)R[n].length();++i){
		ed[i]=R[n].substr(0,i);
		reverse(ed[i].begin(),ed[i].end());
	}
	for(int i=1;i<=m;++i){
		ans+='0';
		ll tmp=check(ans);
		if(tmp<=k){
			k-=tmp;
			ans.back()='1';
		}
		if(ed[i]==ans){
			if(!k){cout<<ans<<'\n';return 0;}
			--k;	
		}
	}
	cout<<ans<<'\n';
	return 0;
}