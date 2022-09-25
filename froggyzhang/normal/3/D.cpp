#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
typedef pair<int,int> pii;
int n,m,a[N],b[N],pos[N];
string s,t;
ll ans;
priority_queue<pii,vector<pii>,greater<pii> > q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	t=s;
	n=s.length();
	for(int i=0;i<n;++i){
		if(s[i]=='?')pos[++m]=i,t[i]=')';	
	}
	for(int i=1;i<=m;++i){
		cin>>a[i]>>b[i];
		ans+=b[i];
	}
	int sum=0;
	for(int i=0,u=0;i<n;++i){
		if(s[i]=='(')++sum;
		else --sum;
		if(s[i]=='?')u++,q.emplace(a[u]-b[u],pos[u]);
		if(sum<0){
			if(q.empty()){
				cout<<-1<<'\n';return 0;
			}
			ans+=q.top().first;
			t[q.top().second]='(';
			q.pop();
			sum+=2;
		}
	}
	if(sum){
		cout<<-1<<'\n';return 0;
	}
	cout<<ans<<'\n'<<t<<'\n';
	return 0;
}