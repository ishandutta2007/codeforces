#include <bits/stdc++.h>

using namespace std;

#define ST first
#define ND second

const int INF = 1000*1000*1000;
const int MAXN = 1000*1000+10;
int n,k,id=1,R,log2n;
pair<int,int>o_o[MAXN];
vector<int>V[MAXN];
int a[MAXN];
stack<pair<int,int> >S;

struct Node {
	int g,f;
};

Node T[(1<<21)];

void propagate(int x) {
	T[2*x].g += T[x].g;
	T[2*x+1].g += T[x].g;
	T[x].g = 0;
}

void updateTf(int a) {
	while(a>1) {
		a/=2;
		T[a].f = max(T[2*a].f+T[2*a].g,T[2*a+1].f+T[2*a+1].g);
	}
}

void update(int a,int b,int c) {
	a+=R; b+=R;
	for(int i=log2n; i>0;i--) {
		propagate(a/(1<<i));
		propagate(b/(1<<i));
	}
	int pa=a,pb=b;
	T[a].g+=c; if(a!=b) T[b].g+=c;
	while(a/2!=b/2) {
		if(a%2==0) T[a+1].g+=c;
		if(b%2==1) T[b-1].g+=c;
		a/=2;
		b/=2;
	}
	updateTf(pa); updateTf(pb);
}

int query(int a, int b) {
	a+=R; b+=R;
	for(int i=log2n; i>0;i--) {
		propagate(a/(1<<i));
		propagate(b/(1<<i));
	}
	updateTf(a); updateTf(b);
	int w = max(T[a].g,T[b].g);
	while(a/2!=b/2) {
		if(a%2==0) w=max(w,T[a+1].g+T[a+1].f);
		if(b%2==1) w=max(w,T[b-1].g+T[b-1].f);
		a/=2;
		b/=2;
	}
	return w;
}

void dfs(int x) {
	o_o[x].ST =id++;
	for(auto nbh:V[x])
		if(o_o[nbh].ST==0) dfs(nbh);
	o_o[x].ND = id;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=0; i<n;i++) {
		cin>>a[i];
	}
	S.push({INF,n});
	for(int i=n-1; i>=0;i--) {
		while(!S.empty()&&S.top().ST<=a[i])
			S.pop();
		V[i].push_back(S.top().ND);
		V[S.top().ND].push_back(i);
		S.push({a[i],i});
	}
	R = pow(2,(int)log2(n+1)+1);
	log2n = log2(R);
	dfs(n);
	for(int i=0; i<k;i++)
		update(o_o[i].ST,o_o[i].ND-1,1);
	for(int i=k;i<n;i++) {
		cout<<query(1,n+1)<<" ";
		update(o_o[i-k].ST,o_o[i-k].ND-1,-1);
		update(o_o[i].ST,o_o[i].ND-1,1);
	}
	cout<<query(1,n+1);
	return 0;
}