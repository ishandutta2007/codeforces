#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 100*1000+10;
int n,m;
vi V[nax];
int hsh[nax];
int num[nax];
int p[nax];

int distq(int x,int y) {
	int w1 = abs(x-y);
	int w2=n-w1;
	return min(w1,w2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	cin>>n>>m;
	bool ok=1;
	for(int a,b,i=0; i<m;i++) {
		cin>>a>>b;
		V[a].PB(b);
		V[b].PB(a);
	}
	for(int k=0; k<5;k++) {
		for(int i=1; i<=n;i++) {
			hsh[i] = rand()%(1000*1000+1);
			num[i]=0;
		}
		for(int i=1; i<=n;i++) {
			for(auto it:V[i]) {
				num[i]+=hsh[distq(it,i)];
			}
		}
		p[1] = 0;
		int w = p[1];
		for(int i=2; i<=n;i++) {
			while (w > 0 && num[w+1] != num[i]) w = p[w];
			if(num[w+1]==num[i]) w++;
			p[i]=w;
		}
		int okres = n-p[n];
		if(n%okres!=0||okres==n) ok=0;
	}
	if(!ok) {
		cout<<"No";
	}
	else {
		cout<<"Yes";
	}
	
}