#include<bits/stdc++.h>
using namespace std;
#define N 600060
typedef long long ll;
const int all=(1<<30)-1;
int n,nxt[N],w[N],anc[N];
ll now;
__int128 ans;
char s[N];
map<int,int> mp;
void Output(__int128 x){
	static int buf[233],len;
	if(!x){cout<<0<<'\n';return;}	
	while(x)buf[++len]=x%10,x/=10;
	while(len)cout<<(char)(buf[len--]+'0');
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1,j=0;i<=n;++i){
		static int st[N],top;
		cin>>s[i]>>w[i];
		s[i]='a'+(s[i]-'a'+ans)%26;
		w[i]=(ans&all)^w[i];
		while(j&&s[j+1]^s[i])j=nxt[j];
		if(i>1)j+=s[i]==s[j+1];
		nxt[i]=j;
		anc[i-1]=s[i]==s[nxt[i-1]+1]?anc[nxt[i-1]]:nxt[i-1];
		for(int k=i-1;k>=1;){
			if(s[k+1]==s[i])k=anc[k];
			else{
				int x=w[*lower_bound(st+1,st+top+1,i-k)];
				--mp[x];
				now-=x;
				if(!mp[x])mp.erase(x);
				k=nxt[k];
			}
		}
		while(top&&w[i]<=w[st[top]])--top;
		int qwq=0;
		vector<int> D;
		for(auto it=mp.upper_bound(w[i]);it!=mp.end();++it){
			now+=1LL*(w[i]-it->first)*(it->second);
			qwq+=it->second;
			D.push_back(it->first);
		}
		for(auto x:D)mp.erase(x);
		mp[w[i]]+=qwq;
		st[++top]=i;
		if(i>1&&s[i]==s[1]){
			now+=w[i];
			++mp[w[i]];
		}
		ans+=now+w[st[1]];
		Output(ans);
	}
	return 0;
}