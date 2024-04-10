#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,mx[26];
char s[N];
void Solve(){
	cin>>(s+1);
	n=strlen(s+1);
	memset(mx,0,sizeof(mx));
	for(int i=1;i<=n;++i){
		mx[s[i]-'a']=i;
	}
	int mn=n;
	for(int i=0;i<26;++i){
		if(mx[i])mn=min(mn,mx[i]);
	}
	for(int i=mn;i<=n;++i){
		cout<<s[i];
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}