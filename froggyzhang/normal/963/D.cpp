#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
string s,t;
int n,m,ans[N],nxt[N],lim[N],len[N];
vector<int> p[N];
int Solve(const vector<int> &p,int lim,int len){
	if(p.size()<lim)return -1;
	int ans=1e9;
	for(int i=lim-1;i<(int)p.size();++i){
		ans=min(ans,p[i]-p[i-lim+1]+len);
	}
	return ans;
}
class Trie{
	int cnt;
	struct node{
		int ch[26],ed;
	}t[N];
public:
	Trie(){cnt=1;}
	void Insert(const string &s,int id){
		int u=1;
		for(auto _c:s){
			int c=_c-'a';
			if(!t[u].ch[c]){
				t[u].ch[c]=++cnt;
			}
			u=t[u].ch[c];	
		}
		t[u].ed=id;
	}
	void Run(const string &s){
		int len=s.length();
		for(int i=0;i<len;++i){
			int u=1;
			for(int j=0;j<300&&i+j<n;++j){
				int c=s[i+j]-'a';
				u=t[u].ch[c];
				if(!u)break;
				if(t[u].ed){
					p[t[u].ed].push_back(i+j);
				}
			}
		}
	}
}T;
void init(const string &s){
	nxt[0]=-1;
	for(int i=1,j=-1;i<(int)s.length();++i){
		while(~j&&s[j+1]^s[i])j=nxt[j];
		j+=s[j+1]==s[i];
		nxt[i]=j;
	}
}
int Query(string t,int lim){
	init(t);
	vector<int> p;
	for(int i=0,j=-1;i<n;++i){
		while(~j&&((j==n-1)||t[j+1]^s[i]))j=nxt[j];
		j+=t[j+1]==s[i];
		if(j==(int)t.length()-1){
			p.push_back(i);
		}
	}
	return Solve(p,lim,t.length());
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	n=s.length();
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>lim[i]>>t;
		len[i]=t.length();
		if(t.length()>300){
			ans[i]=Query(t,lim[i]);
		}
		else{
			T.Insert(t,i);
		}
	}
	T.Run(s);
	for(int i=1;i<=m;++i){
		if(!ans[i])ans[i]=Solve(p[i],lim[i],len[i]);
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}