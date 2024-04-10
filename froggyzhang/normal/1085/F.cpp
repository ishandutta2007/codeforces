#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
map<char,int> mp;
int n,Q;
char s[N];
struct BIT{
	int b[N];
	inline int lowbit(int x){return x&(-x);}
public:
	inline void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=1;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
	inline int Query(int l,int r){
		return Ask(r)-Ask(l-1);
	}
}B[3];
set<int> S[3];
void Change(int u,int x,int opt){
	B[x].Add(u,opt);
	if(opt==1)S[x].insert(u);
	else S[x].erase(u);
}
int calc(){
	int ans=n;
	for(int i=0;i<3;++i){
		int x=(i+1)%3,y=(i+2)%3;
		// i->x , y->i
		if(S[y].empty())continue;
		if(S[x].empty()){ans-=S[i].size();continue;}
		int lx=*S[x].begin(),rx=*S[x].rbegin();
		int ly=*S[y].begin(),ry=*S[y].rbegin();
		if(lx>=ly)ans-=B[i].Query(ly,lx);
		if(ry>=rx)ans-=B[i].Query(rx,ry);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	cin>>(s+1);
	mp['P']=0,mp['R']=1,mp['S']=2;
	for(int i=1;i<=n;++i){
		Change(i,mp[s[i]],1);	
	}
	cout<<calc()<<'\n';
	while(Q--){
		int u;
		char x;
		cin>>u>>x;
		Change(u,mp[s[u]],-1);
		Change(u,mp[s[u]=x],1);
		cout<<calc()<<'\n';
	}
	return 0;
}