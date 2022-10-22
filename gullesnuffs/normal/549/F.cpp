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

int a[300005];
vector<int> v[1000005];
vector<pair<int, int> > order;
set<int> done;
int S[300005];
int n, k;

int getNum(int val, int l, int r){
	val %= k;
	val += k;
	val %= k;
	vector<int>::iterator a=upper_bound(v[val].begin(), v[val].end(), l);
	vector<int>::iterator b=upper_bound(v[val].begin(), v[val].end(), r);
	//for(int i=0; i < v[val].size(); ++i)
	//	printf("%d ", v[val][i]);
	//printf("\n");
	//int a=v[val].lower_bound(l);
	//int b=v[val].lower_bound(r);
	//printf("val = %d, l = %d, r = %d, ret = %d\n", val, l, r, b-a);
	return b-a;
}

int main(){
	scanf("%d%d", &n, &k);
	S[0]=0;
	v[0].push_back(0);
	ll ans=-n;
	rep(i,0,n){
		scanf("%d", a+i);
		S[i+1]=(S[i]+a[i])%k;
		v[S[i+1]].push_back(i+1);
		order.push_back(make_pair(-a[i], i));
		a[i]%=k;
	}
	sort(order.begin(), order.end());
	rep(i,0,order.size()){
		int cur=order[i].second;
		//printf("cur = %d\n", cur);
		set<int>::iterator it=done.lower_bound(cur);
		int l, r;
		if(it == done.end())
			r=n;
		else
			r=*it;
		if(it == done.begin())
			l=-1;
		else{
			--it;
			l=*it;
		}
		int sum=-a[cur];
		if(cur-l < r-cur){
			for(int j=cur; j > l; --j){
				sum += a[j];
				sum%=k;
				ans += getNum((S[cur+1]-sum)%k, cur, r);
			}
		}
		else{
			for(int j=cur; j < r; ++j){
				sum += a[j];
				sum%=k;
				ans += getNum((S[cur]+sum)%k, l, cur);
			}
		}
		done.insert(cur);
	}
	cout << ans << endl;
}