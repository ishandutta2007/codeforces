#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int nax = 200*1000+10,INF=1e9;
int n,m,R=1;

struct Node {
	int sm1[10], sm2[10];
};
Node T[(1<<19)];

void update(int a,int x) {
	a+=R;
	ll pow = 10;
	for(int i=0; i<10; i++) {
		if((x%pow)/(pow/10)==0) T[a].sm1[i] = INF;
		else T[a].sm1[i] = x;
		pow*=10;
	}
	while(a>1) {
		a/=2;
		for(int i=0; i<10; i++) {
			if(T[2*a].sm1[i]+T[2*a].sm2[i]<=T[2*a+1].sm1[i]+T[2*a+1].sm2[i]) {
				T[a].sm1[i] = T[2*a].sm1[i];
				T[a].sm2[i] = T[2*a].sm2[i];
			} else {
				T[a].sm1[i] = T[2*a+1].sm1[i];
				T[a].sm2[i] = T[2*a+1].sm2[i];
			}
			if(T[a].sm1[i]+T[a].sm2[i]>T[2*a].sm1[i]+T[2*a+1].sm1[i]) {
				T[a].sm1[i] = min(T[2*a].sm1[i],T[2*a+1].sm1[i]);
				T[a].sm2[i] = max(T[2*a].sm1[i],T[2*a+1].sm1[i]);
			}
		}
	}
}

void assign(int (&x)[10], int (&y)[10],int a) {
	for(int i=0; i<10; i++) {
		if(T[a].sm1[i]<=x[i]) {
			y[i] = x[i];
			x[i] = T[a].sm1[i];
		} else if(T[a].sm1[i]<=y[i]) {
			y[i] = T[a].sm1[i];
		}
		if(T[a].sm2[i]<=x[i]) {
			y[i] = x[i];
			x[i] = T[a].sm2[i];
		} else if(T[a].sm2[i]<=y[i]) {
			y[i] = T[a].sm2[i];
		}
	}
}

int query(int a,int b) {
	a+=R; b+=R;
	int w1[10], w2[10];
	for(int i=0; i<10; i++) {
		w1[i] = w2[i] = 2*INF;
	}
	assign(w1,w2,a);
	if(a!=b) assign(w1,w2,b);
	while(a/2!=b/2) {
		if(a%2==0) assign(w1,w2,a+1);
		if(b%2==1) assign(w1,w2,b-1);
		a/=2; b/=2;
	}
	int ans = 2*INF;
	for(int i=0; i<10; i++) {
		if(w2[i]!=INF) {
			ans =min(ans,w1[i]+w2[i]);
		}
	}
	return ans==2*INF?-1:ans;
}
	
		

int main() {_
	cin>>n>>m;
	while(R<=n) {
		R*=2;
	}
	for(int i=1; i<2*R; i++) for(int j=0; j<10; j++) T[i].sm1[j] = T[i].sm2[j] = INF;
	for(int x,i=1; i<=n;i++) {
		cin>>x;
		update(i,x);
	}
	for(int t,a,b,i=0; i<m;i++) {
		cin>>t>>a>>b;
		if(t==2) {
			cout<<query(a,b)<<"\n";
		} else {
			update(a,b);
		}
	}
	
}