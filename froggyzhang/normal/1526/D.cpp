#include<bits/stdc++.h>
using namespace std;
#define N 100020
const int inf=1e9;
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
int T,n;
char s[N];
char t[4]={'A','N','O','T'};
map<char,int> mp;
struct BIT{
	ll b[N];
	inline int lowbit(int x){return x&(-x);}
	inline void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	inline ll Ask(int x){
		ll ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}B;
void Solve(){
	array<vector<int>,4> a;
	array<int,4> p,nb,cnt;
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		int x=mp[s[i]];
		++cnt[x];
		a[x].push_back(i);
	}	
	for(int i=0;i<4;++i)p[i]=i;
	ll mx=-1;
	do{
		for(int i=1;i<=n;++i)B.b[i]=0;
		ll tot=0;
		for(int i=0;i<4;++i){
			int u=p[i];
			for(auto x:a[u]){
				tot+=B.Ask(n)-B.Ask(x);
				B.Add(x,1);		
			}
		}
		if(tot>mx){
			nb=p;
			mx=tot;
		}
	}while(next_permutation(p.begin(),p.end()));
	for(int i=0;i<4;++i){
		int u=nb[i];
		while(cnt[u]--)putchar(t[u]);
	}
	putchar('\n');
}
int main(){
	mp['A']=0;
	mp['N']=1;
	mp['O']=2;
	mp['T']=3;
	T=read();
	while(T--){
		scanf("%s",s+1);
		Solve();	
	}
	return 0;
}