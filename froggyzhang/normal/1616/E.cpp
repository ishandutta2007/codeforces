#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const ll inf=1e18;
class BIT{
	int b[N],Len;
	inline int lowbit(int x){return x&(-x);}
public:
	void init(int n){
		Len=n;
		for(int i=1;i<=n;++i)b[i]=0;
	}	
	inline void Add(int x,int d){
		while(x)b[x]+=d,x-=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x<=Len)ans+=b[x],x+=lowbit(x);
		return ans;
	}
}B;
int n;
char s[N],t[N];
queue<int> q[26];
void Solve(){
	cin>>n;
	cin>>(s+1)>>(t+1);
	B.init(n);
	for(int i=0;i<26;++i)while(!q[i].empty())q[i].pop();
	for(int i=1;i<=n;++i){
		q[s[i]-'a'].push(i);
	}
	ll ans=inf;
	ll now=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<t[i]-'a';++j){
			if(!q[j].empty())ans=min(ans,now+B.Ask(q[j].front())+q[j].front()-i);
		}
		int c=t[i]-'a';
		if(q[c].empty())break;
		now+=q[c].front()+B.Ask(q[c].front())-i;
		B.Add(q[c].front(),1);
		q[c].pop();
	}
	cout<<(ans==inf?-1:ans)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}