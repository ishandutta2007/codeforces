#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int n,m;
int a[500005],b[500005];
int Left[500005];

long long calc(int pos, int dir){
	rep(i,0,n){
		Left[i]=0;
	}
	rep(i,0,m)
		++Left[b[i]];
	--Left[pos];
	if(Left[pos] < 0)
		return -1;
	long long len=0;
	int prepos=a[pos];
	for(int i=0; i < m-1; ++i){
		if(pos == 0)
			dir=1;
		if(pos == n-1)
			dir=-1;
		pos += dir;
		--Left[pos];
		if(Left[pos] < 0)
			return -1;
		len += abs(prepos-a[pos]);
		prepos=a[pos];
	}
	return len;
}

long long ans=-1;

bool update(int pos, int dir){
	long long ret=calc(pos,dir);
	if(ret == -1)
		return 0;
	if(ans == -1)
		ans=ret;
	if(ans != ret){
		puts("-1");
		exit(0);
		return 1;
	}
	return 0;
}

int has[500005];

int main(){
	scanf("%d", &n);
	rep(i,0,n){
		scanf("%d", a+i);
		--a[i];
	}
	scanf("%d", &m);
	rep(i,0,m){
		scanf("%d", b+i);
		--b[i];
		++has[b[i]];
	}
	update(0,1);
	update(n-1,1);
	int numDiffLen=0;
	rep(i,0,n){
		bool check=(has[i] != has[i+1]);
		if(!check && numDiffLen < 5 && i && has[i]-has[i-1] != has[i+1]-has[i]){
			check=1;
			++numDiffLen;
		}
		if(check){
			update(i,1);
			update(i,-1);
			if(i+1 < n){
				update(i+1,1);
				update(i+1,-1);
			}
			if(i+2 < n){
				update(i+2,1);
				update(i+2,-1);
			}
			if(i-1 >= 0){
				update(i-1,1);
				update(i-1,-1);
			}
			if(i-2 >= 0){
				update(i-2,1);
				update(i-2,-1);
			}
		}
	}
	cout << ans << endl;
}