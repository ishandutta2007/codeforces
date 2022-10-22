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

int a[3005];

int main(){
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> a[i];
	}
	vector<pair<int, int> > ans;
	rep(i,0,n){
		int Min=i;
		rep(j,i,n){
			if(a[j] < a[Min])
				Min=j;
		}
		if(Min != i){
			ans.push_back(make_pair(i,Min));
			//cout << i << " " << Min << endl;
			swap(a[i],a[Min]);
		}
	}
	cout << ans.size() << endl;
	rep(i,0,ans.size())
		cout << ans[i].first << " " << ans[i].second << endl;
}