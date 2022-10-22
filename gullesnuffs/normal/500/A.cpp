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

int a[100005];
bool ok[100005];

int main(){
	int n, t;
	cin >> n >> t;
	rep(i, 0, n-1)
		cin >> a[i];
	ok[t-1]=1;
	for(int i=n-2; i >= 0; --i)
		if(ok[i+a[i]])
			ok[i]=1;
	puts(ok[0]?"YES":"NO");
}