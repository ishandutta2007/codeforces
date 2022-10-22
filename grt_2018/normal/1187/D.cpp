#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 300*1000+10;
const int INF = 1000*1000*1000;
int t,n,R;
int arr[nax],brr[nax],T[(1<<20)];
vi pos[nax];

void update(int a,int x) {
	a+=R;
	T[a]=x;
	while(a>1) {
		a/=2;
		T[a]=min(T[2*a],T[2*a+1]);
	}
}

int query(int a,int b) {
	a+=R; b+=R;
	int w = min(T[a],T[b]);
	while(a/2!=b/2) {
		if(a%2==0) w=min(w,T[a+1]);
		if(b%2==1) w=min(w,T[b-1]);
		a/=2; b/=2;
	}
	return w;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--) {
		cin>>n;
		R=1;
		while(R<n) {
			R*=2;
		}
		for(int i=1; i<2*R;i++) T[i] = INF;
		for(int i=1; i<=n;i++) pos[i].clear();
		for(int i=0; i<n;i++) {
			cin>>arr[i];
			update(i,arr[i]);
		}
		for(int i=0; i<n;i++) cin>>brr[i];
		for(int i=n-1; i>=0;i--) {
			pos[arr[i]].PB(i);
		}
		bool same = 1;
		for(int i=0; i<n;i++) {
			if(pos[brr[i]].empty()) {
				same = 0; break;
			}
			int p = pos[brr[i]].back(); pos[brr[i]].pop_back();
			if(brr[i]>query(0,p)) {
				same=0; break;
			}
			update(p,INF);
		}
		if(same) cout<<"YES\n";
		else cout<<"NO\n";
	}
}