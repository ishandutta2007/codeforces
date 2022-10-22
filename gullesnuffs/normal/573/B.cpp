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

int h[100005];
int ans=0;
int n;
int dis[100005];

void f(){
	int minHeight=0;
	rep(i,0,n){
		//dis[i]=min(dis[i], minHeight+i+1);
		dis[i]=min(dis[i], h[i]);
		dis[i]=min(dis[i], dis[i-1]+1);
		//minHeight=min(minHeight, h[i]-i);
	}
}

int main(){
	scanf("%d", &n);
	rep(i,0,n+2){
		if(i >= 1 && i <= n)
			scanf("%d", h+i);
		dis[i]=10000000;
	}
	n += 2;
	f();
	rep(i,0,n/2){
		swap(dis[i], dis[n-i-1]);
		swap(h[i], h[n-i-1]);
	}
	f();
	rep(i,0,n)
		ans=max(ans, dis[i]);
	printf("%d\n", ans);
}