#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
int n,m;
vector<pair<pair<ll,int>,int> >e;
int eu[N],ev[N];
stack<int>s;
ll pw[N];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++) pw[i]=1;
	for(int i=1; i<=m ;i++){
		ll w;ll x;
		cin >> w >> x;
		e.push_back({{w,-x},i});
	}
	int cur=1;
	sort(e.begin(),e.end());
	for(auto c:e){
		c.fi.se*=-1;
		if(c.fi.se==1){
			cur++;
			s.push(cur);
			eu[c.se]=1;
			ev[c.se]=cur;
		}
		else{
			while(!s.empty() && pw[s.top()]==s.top()-1) s.pop();
			if(s.empty()) return cout << "-1\n",0;
			int x=s.top();
			pw[x]++;
			eu[c.se]=pw[x];
			ev[c.se]=x;
		}
	}
	for(int i=1; i<=m ;i++){
		cout << eu[i] << ' ' << ev[i] << endl;
	}
}