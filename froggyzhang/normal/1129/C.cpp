#include<bits/stdc++.h>
using namespace std;
#define N 3003
typedef long long ll;
const int mod=1e9+7;
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
set<string> ban;
string now;
int Q,ans,u;
struct Trie{
	int ch[2];	
}trie[N*N];
int dp[N*N],tot;
vector<int> st;
void Insert(string &s){
	int u=1;
	st.clear();
	st.push_back(1);
	for(int i=0;i<(int)s.length();++i){
		int c=s[i]-'0';
		bool need=false;
		if(!trie[u].ch[c]){
			trie[u].ch[c]=++tot;	
			need=true;
		}	
		u=trie[u].ch[c];
		if(need){
			for(int j=1;j<=4&&i-j+1>=0;++j){
				if(!ban.count(s.substr(i-j+1,j))){
					dp[u]=(dp[u]+dp[st[(int)st.size()-j]])%mod;
				}
			}	
			ans=(ans+dp[u])%mod;
		}
		st.push_back(u);
	}
}
int main(){
	dp[1]=tot=1;
	Q=read();
	ban.insert("1100");
	ban.insert("1010");
	ban.insert("0111");
	ban.insert("1111");
	while(Q--){
		now+=read()+'0';
		string s=now;
		reverse(s.begin(),s.end());
		Insert(s);	
		printf("%d\n",ans);
	}
	return 0;
}