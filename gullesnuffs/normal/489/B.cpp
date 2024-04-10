#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int a[105],b[105];
int main(){
	int n,m;
	cin >> n;
	rep(i,0,n)
		cin >> a[i];
	cin >> m;
	rep(i,0,m)
		cin >> b[i];
	sort(a,a+n);
	sort(b,b+m);
	int pos=0;
	int ans=0;
	rep(i,0,n){
		while(pos != m && b[pos] < a[i]-1)
			++pos;
		if(pos == m)
			continue;
		if(b[pos] > a[i]+1)
			continue;
		++ans;
		++pos;
	}
	cout << ans << endl;
}