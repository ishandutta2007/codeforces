#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

struct Node {
	int delta,maxE,minE,r,l,f;
};

const int nax = 200*1000+1;
int n,q,R;
int t[nax];
Node T[(1<<19)];

void update(int a) {
	a+=R;
	T[a].delta = T[a].maxE=T[a].minE= -T[a].delta;
	T[a].r = T[a].l= -T[a].maxE;
	while(a>1) {
		a/=2;
		T[a].delta = T[2*a].delta + T[2*a+1].delta;
		T[a].maxE = max(T[2*a].maxE,T[2*a+1].maxE+T[2*a].delta);
		T[a].minE = min(T[2*a].minE,T[2*a+1].minE+T[2*a].delta);
		T[a].l = max({T[2*a].l,T[2*a+1].l-T[2*a].delta,T[2*a].maxE - 2*T[2*a+1].minE-2*T[2*a].delta});
		T[a].r = max({T[2*a].r,T[2*a+1].r-T[2*a].delta,T[2*a+1].maxE - 2*T[2*a].minE + T[2*a].delta});
		T[a].f = max({T[2*a].f,T[2*a+1].f,T[2*a].maxE+T[2*a+1].r-T[2*a].delta,T[2*a].l+T[2*a+1].maxE+T[2*a].delta});
	}
}

void coutTree() {
	for(int i=1; i<2*R;i++) {
		cout<<i<<" : "<<T[i].delta<<" "<<T[i].f<<" "<<T[i].maxE<<" "<<T[i].minE<<"\n";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    R = 1;
    while(R<(2*(n-1))) {
		R*=2;
	}
    for(int i=0; i<2*(n-1);i++) {
		char c;
		cin>>c;
		if(c=='(') {
			t[i]=1;
			T[i+R].delta = -1;
			update(i);
		}
		else {
			t[i]=-1;
			T[i+R].delta = 1;
			update(i);
		}
	}
	cout<<T[1].f<<"\n";
	//coutTree();
	while(q--) {
		int x,y;
		cin>>x>>y;
		if(t[--x]!=t[--y]) {
			t[x]=-t[x]; t[y]=-t[y];
			update(x); update(y);
		}
		cout<<T[1].f<<"\n";
	}
}