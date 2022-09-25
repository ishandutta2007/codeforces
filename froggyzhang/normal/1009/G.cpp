#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const int all=(1<<6)-1;
int a[N],n,m,cnt[6],g[N];
char s[N];
bool check(){
	static int s[1<<6];
	for(int i=1;i<(1<<6);++i){
		s[i]=s[i^(i&-i)]+cnt[__builtin_ctz(i)];
	}
	int t=s[all];
	for(int i=1;i<(1<<6);++i){
		if(g[all^i]>t-s[i]){
			return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>(s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		++cnt[s[i]-'a'];
		a[i]=all;
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		int x;
		cin>>x;
		string t;
		cin>>t;
		a[x]=0;
		for(int j=0;j<(int)t.length();++j){
			a[x]|=1<<t[j]-'a';	
		}
	}
	for(int i=1;i<=n;++i){
		++g[a[i]];	
	}
	for(int j=0;j<6;++j){
		for(int i=0;i<(1<<6);++i){
			if(i>>j&1)g[i]+=g[i^(1<<j)];	
		}
	}
	if(!check()){
		cout<<"Impossible\n";
		return 0;	
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<(1<<6);++j){
			if((j&a[i])==a[i])--g[j];	
		}
		for(int j=0;j<6;++j){
			if(cnt[j]&&a[i]>>j&1){
				--cnt[j];
				if(check()){
					cout<<char('a'+j);
					break;
				}
				++cnt[j];
			}	
		}	
	}
	return 0;
}