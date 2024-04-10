#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200*1000+10;
int n,p[nax],beg[nax],e[nax],lim;
string t;
vector<string>s;
int trie[nax][26],finish[nax],nxt=1,len=0;

void add(string &q) {
	int node = 0;
	for(auto it:q) {
		if(trie[node][it-'a']==0) {
			node = trie[node][it-'a']=nxt;
			nxt++;
		} else {
			node = trie[node][it-'a'];
		}
	}
	finish[node]++;
}

int cnt_b(int i) {
	int w = 0,node = 0;
	while(i<(int)t.size()) {
		if(trie[node][t[i]-'a']==0) {
			return w;
		} else {
			node = trie[node][t[i]-'a'];
			w+=finish[node];
		}
		i++;
	}
	return w;
}

void kmp(string &q) {
	p[1] = 0;
	for(int i=2; i<=(int)q.size(); i++) {
		int w = p[i-1];
		while(w>0&&q[w]!=q[i-1]) w = p[w];
		if(q[w]==q[i-1]) w++;
		p[i] = w;
	}
}

void kmpSearch(string &q) {
	int w = 0;
	for(int i=1; i<=(int)t.size(); i++) {
		while(w>0&&t[i-1]!=q[w]) w = p[w];
		if(q[w]==t[i-1]) w++;
		if(w==(int)q.size()) {
			beg[i-(int)q.size()+1]++;
			e[i]++;
		}
	}
}

int main() {_
	cin>>t>>n;
	for(int i=0; i<n;i++) {
		string tmp;
		cin>>tmp;
		s.PB(tmp);
		len+=(int)tmp.size();
	}
	lim = sqrt(len);
	for(auto &it:s) {
		if((int)it.size()>lim) {
			kmp(it); kmpSearch(it);
		} else {
			add(it);
		}
		reverse(it.begin(),it.end());
	}
	for(int i=1; i<=(int)t.size(); i++) {
		beg[i]+=cnt_b(i-1);
	}
	reverse(t.begin(),t.end());
	for(int i=0; i<nxt;i++) {
		for(int j=0; j<26;j++) {
			trie[i][j] = 0;
		}
		finish[i]=0;
	}
	nxt = 1;
	for(auto &it: s) {
		if((int)it.size()<=lim) {
			add(it);
		}
	}
	for(int i=1; i<=(int)t.size(); i++) {
		e[(int)t.size()-i+1]+=cnt_b(i-1);
	}
	ll ans = 0;
	for(int i=1; i<(int)t.size(); i++) {
		ans+=(ll)e[i]*beg[i+1];
	}
	cout<<ans;
}