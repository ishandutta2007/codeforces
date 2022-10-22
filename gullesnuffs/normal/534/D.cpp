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

int a[200005];
queue<int> q[200005];
vector<int> ans;

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n){
		scanf("%d", a+i);
		q[a[i]].push(i);
	}
	int pos=0;
	rep(i,0,n){
		while(pos >= 0 && q[pos].empty())
			pos -= 3;
		if(pos < 0){
			puts("Impossible");
			return 0;
		}
		ans.push_back(q[pos].front());
		q[pos].pop();
		++pos;
	}
	if(ans.size() != n){
			puts("Impossible");
			return 0;
	}
	puts("Possible");
	rep(i,0,n)
		printf("%d ", ans[i]+1);
	printf("\n");
	exit(0);
}