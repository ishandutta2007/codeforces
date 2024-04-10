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

struct Node {
	int f,g,id;
};

Node mx(Node &n1,Node &n2) {
	if(n1.f<n2.f) return n2;
	return n1;
}
	
const int nax = 500*1000+10;
int n,R;
pi seg[nax];
Node T[(1<<21)];
vi V[nax];

void update(int a,int x,int y) {
	a+=R;
	T[a] = {x,a-R,y};
	while(a>1) {
		a/=2;
		T[a] = mx(T[2*a],T[2*a+1]);
	}
}

Node query(int a,int b) {
	a+=R; b+=R;
	Node w = mx(T[a],T[b]);
	while(a/2!=b/2) {
		if(a%2==0) w=mx(w,T[a+1]);
		if(b%2==1) w=mx(w,T[b-1]);
		a/=2; b/=2;
	}
	return w;
}

bool visited[nax];
int ans;

void dfs(int x) {
	visited[x]=1;
	ans++;
	for(int nbh:V[x]) {
		if(!visited[nbh]) {
			dfs(nbh);
		}
	}
}

int main() {_
	cin>>n;
	R=1;
	while(R<=2*n) R*=2;
	for(int i=1; i<=n; i++) {
		cin>>seg[i].ST>>seg[i].ND;
		update(seg[i].ST,seg[i].ND,i);
	}
	int cnt = 0;
	for(int i=1; i<=n; i++) {
		Node w = query(seg[i].ST+1,seg[i].ND);
		vector<Node> v = {};
		while(w.f>seg[i].ND) {
			v.PB(w);
			update(w.g,-1,w.id);
			V[i].PB(w.id);
			V[w.id].PB(i);
			cnt++;
			w = query(seg[i].ST+1,seg[i].ND);
		}
		for(auto it:v) {
			update(it.g,it.f,it.id);
		}
		if(cnt>=n) {
			cout<<"NO";
			return 0;
		}
	}
	if(cnt<n-1) {
		cout<<"NO";
		return 0;
	}
	dfs(1);
	if(ans==n) {
		cout<<"YES";
	} else {
		cout<<"NO";
	}
	
}