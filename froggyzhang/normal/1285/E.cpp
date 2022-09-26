#include<bits/stdc++.h>
using namespace std;
#define N 200002
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
int T,n,cnt[N];
map<int,vector<int> > mp;
map<int,vector<int> > t;
set<int> s;
void Solve(){
	mp.clear();
	s.clear();
	t.clear();
	n=read();
	for(int i=1;i<=n;++i){
		int l=read(),r=read();
		if(l==r)t[l].push_back(i),mp[l].push_back(i),mp[l].pop_back();
		else{
			mp[l].push_back(i);
			mp[r].push_back(-i);
		}
		cnt[i]=0;
	}
	int sd=0,ans=0,las=0;
	bool ok=false;
	for(auto [pos,v]:mp){
		int gg=0;
		for(auto x:v){
			if(x<0){
				s.erase(-x);	
			}
			else{
				s.insert(x);
			}
		}
		if(!t[pos].empty()){
			if(!ok&&s.empty())cnt[t[pos][0]]--;
			ok=true;
			gg=1;
		}
		if(s.empty()){
			++sd;
			if(las&&!gg)--cnt[las];
		}
		if((int)s.size()==1){
			++cnt[las=(*s.begin())];
			if(!ok)--cnt[las];
		}
		else las=0;
		if(!s.empty())ok=true;
		else ok=false;
	}
	for(int i=1;i<=n;++i){
		ans=max(ans,sd+cnt[i]);
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}