#include<bits/stdc++.h>
using namespace std;
#define N 1000100
const int MX=1e6;
typedef long long ll;
typedef pair<int,int> pii;
int n,a[N],ntp[N];
char s[N];
vector<pii> p[N],jie[N],g[N];
int del[N];
priority_queue<int,vector<int>,greater<int> > q;
void Solve(vector<pii> &A){
	if(A.empty())return;
	vector<int> s;
	s.resize(A.size());
	s[0]=A[0].second;
	for(int i=1;i<(int)A.size();++i){
		s[i]=s[i-1]+A[i].second;
	}
	vector<int> st;
	for(int i=(int)A.size()-1;i>=0;--i){
		int jb=(!i?0:s[i-1]);
		while(!st.empty()&&s[i]<=s[st.back()])st.pop_back();
		st.push_back(i);
		if(s[st[0]]>=jb)continue;
		int pos=-1;
		int l=0,r=st.size();
		while(l<r){
			int mid=(l+r)>>1;
			if(s[st[mid]]<jb){
				pos=A[st[mid]].first;
				l=mid+1;
			}
			else{
				r=mid;
			}
		}
		int L=(!i?1:A[i-1].first+1);
		int R=A[i].first;
		g[L].emplace_back(pos-1,1);
		g[R+1].emplace_back(pos-1,-1);
	}	
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cin>>(s+1);
	for(int i=2;i<=MX;++i){
		if(!ntp[i]){
			for(int j=i+i;j<=MX;j+=i){
				ntp[j]=1;
			}
			for(int j=i;j<=MX;j+=i){
				jie[j].emplace_back(i,0);
			}
			for(int c=1,x=i;;++c){
				for(int j=x;j<=MX;j+=x){
					++jie[j].back().second;
				}
				if(1LL*x*i>MX)break;
				x*=i;	
			}	
		}
	}
	for(int i=1;i<=n;++i){
		for(auto [t,w]:jie[a[i]]){
			p[t].emplace_back(i,s[i]=='*'?w:-w);	
		}
	}
	for(int i=1;i<=MX;++i){
		Solve(p[i]);	
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		for(auto [x,w]:g[i]){
			if(w==1)q.push(x);
			else ++del[x];
		}
		while(!q.empty()&&del[q.top()])--del[q.top()],q.pop();
		if(q.empty())ans+=n-i+1;
		else ans+=q.top()-i+1;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	while(T--)Solve();
	return 0;
}