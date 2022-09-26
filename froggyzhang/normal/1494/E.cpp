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
int n,Q;
map<pair<int,int>,pair<char,char> > mp;
int main(){
	n=read(),Q=read();
	int s1=0,s2=0;
	while(Q--){
		char opt;
		do{opt=getchar();}while(opt!='+'&&opt!='-'&&opt!='?');
		if(opt=='+'){
			int u=read(),v=read(),t=0;
			char c;
			do{c=getchar();}while(!isalpha(c));
			if(u>v)swap(u,v),t=1;
			auto p=make_pair(u,v);
			t?(mp[make_pair(u,v)].second=c):(mp[make_pair(u,v)].first=c);
			if(mp[p].first==mp[p].second)++s2;
			else if(mp[p].first&&mp[p].second)++s1;
		}
		else if(opt=='-'){
			int u=read(),v=read(),t=0;
			if(u>v)swap(u,v),t=1;
			auto p=make_pair(u,v);
			if(mp[p].first==mp[p].second)--s2;
			else if(mp[p].first&&mp[p].second)--s1;
			t?mp[make_pair(u,v)].second=0:mp[make_pair(u,v)].first=0;
		}
		else{
			int k=read();
			if(k&1)printf(s1||s2?"YES\n":"NO\n");
			else printf(s2?"YES\n":"NO\n");	
		}
	}
	return 0;
}