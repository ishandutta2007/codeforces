#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef pair<int,int> pii;
typedef long long ll;

// MAGIC IO
inline char get(void) {
	static char buf[100000], *S = buf, *T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 100000, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
inline void read(int &x) {
	static char c; x = 0; int sgn = 0;
	for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
	for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
	if (sgn) x = -x;
}
void readchar(char& c) {
	while (isspace(c = get()));
}
// END MAGIC IO

const int N = 1<<19;
ll minv[2*N], lazy[2*N];

void push(int i) {
	if(lazy[i]) {
		minv[2*i] += lazy[i];
		minv[2*i+1] += lazy[i];
		lazy[2*i] += lazy[i];
		lazy[2*i+1] += lazy[i];
		lazy[i] = 0;
	}
}

void insert(int l, int r, int v, int i=1, int s=0, int e=N-1) {
	if(l<=s&&e<=r) {
		minv[i] += v;
		lazy[i] += v;
		return;
	}
	push(i);
	int m = (s+e)/2;
	if(l<=m) insert(l,r,v,2*i,s,m);
	if(r>m) insert(l,r,v,2*i+1,m+1,e);
	minv[i] = min(minv[2*i], minv[2*i+1]);
}

int query(int i=1, int s=0, int e=N-1) {
	if(s==e) return 1;
	push(i);
	int m = (s+e)/2;
	return (minv[2*i]<0 ? query(2*i,s,m) : 0)
		+ (minv[2*i+1]<0 ? query(2*i+1,m+1,e) : 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	//cin>>n;
	read(n);

	char t[n];
	int v[n], o[n];
	memset(o,-1,sizeof o);
	vector<pii> vals;
	unordered_map<int,vector<int>> match;
	for(int i=0;i<n;i++) {
		//cin>>t[i]>>v[i];
		readchar(t[i]); read(v[i]);
		if(t[i] == '+') {
			vals.push_back(make_pair(v[i],i));
			match[v[i]].push_back(i);
		} else {
			o[match[v[i]].back()] = i;
			match[v[i]].pop_back();
		}
	}
	sort(vals.begin(),vals.end());
	int m = vals.size();

	int idx[n];
	for(int i=0;i<m;i++) {
		idx[vals[i].second] = i;
		if(o[vals[i].second] != -1) {
			idx[o[vals[i].second]] = i;
		}
	}

	int tot = 0;
	for(int i=0;i<n;i++) {
		if(t[i]=='+') {
			insert(idx[i],idx[i],-v[i]);
			insert(idx[i]+1,m-1,2*v[i]);
			tot++;
		} else {
			insert(idx[i],idx[i],v[i]);
			insert(idx[i]+1,m-1,-2*v[i]);
			tot--;
		}
		cout<<tot-query()<<nl;
	}

	return 0;
}