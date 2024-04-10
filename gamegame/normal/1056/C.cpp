#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
#define fi first
#define se second
int n,m;
pair<int,int>p[2001];
int q[2001];
bool used[2001];
stack<int>s;
bool cmp(pair<int,int>i,pair<int,int>j){
	return i>j;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=2*n ;i++){
		cin >> p[i].fi;
		p[i].se=i;
	}
	for(int i=1; i<=m ;i++){
		int u,v;
		cin >> u >> v;
		q[u]=v;
		q[v]=u;
		if(p[u].fi>p[v].fi) s.push(u);
		else s.push(v);
	}
	sort(p+1,p+2*n+1,cmp);
	int t;
	cin >> t;
	int rnd=0;
	if(t==1){
		while(!s.empty()){
			cout << s.top() << endl;
			used[s.top()]=true;
			used[q[s.top()]]=true;
			int crap;
			cin >> crap;
			rnd++;
			s.pop();
		}
		int ptr=1;
		while(rnd<n){
			while(used[p[ptr].se]) ++ptr;
			cout << p[ptr].se << endl;
			used[p[ptr].se]=true;
			int crap;
			cin >> crap;
			used[crap]=true;
			++rnd;
		}
	}
	else{
		int ptr=1;
		for(int i=1; i<=n ;i++){
			int crap;
			cin >> crap;
			used[crap]=true;
			if(q[crap]!=0){
				cout << q[crap] << endl;
				used[q[crap]]=true;
				continue;
			}
			if(!s.empty()){
				while(!s.empty()){
					if(used[s.top()]){
						s.pop();
						continue;
					}
					cout << s.top() << endl;
					used[s.top()]=true;
					used[q[s.top()]]=true;
					int crap;
					cin >> crap;
					i++;
					s.pop();
				}
			}
			while(used[p[ptr].se]) ++ptr;
			cout << p[ptr].se << endl;
			used[p[ptr].se]=true;
		}
	}
}