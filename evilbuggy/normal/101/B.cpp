#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

int s[100005], t[100005];
pair<int,int> arr[100005];

bool cmp(pair<int,int> &x, pair<int,int> &y){
	return (x.second != y.second)?(x.second < y.second):(x.first < y.first);
}

int tr[2000005][2], val[2000005];
int ptr = 2;

void update(int v, int l, int r, int ind, int x){
	if(l == r){
		(val[v] += x) %= mod;
		return;
	}
	int m = (l+r)>>1;
	if(ind <= m){
		if(tr[v][0] == 0){
			tr[v][0] = ptr++;
		}
		update(tr[v][0], l, m, ind, x);
	}
	else{
		if(tr[v][1] == 0){
			tr[v][1] = ptr++;
		}
		update(tr[v][1], m + 1, r, ind, x);
	}
	val[v] = (val[tr[v][0]] + val[tr[v][1]])%mod;
}

int query(int v, int s, int e, int l, int r){
	if(l <= s && e <= r)return val[v];
	if(e < l || r < s || r < l)return 0;
	int m = (s + e)>>1;
	return (query(tr[v][0], s, m, l, r) + query(tr[v][1], m + 1, e, l, r))%mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= m; i++){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr + 1, arr + m + 1, cmp);
	for(int i = 1; i <= m; i++){
		s[i] = arr[i].first;
		t[i] = arr[i].second;
	}
	memset(tr, 0, sizeof(tr));
	memset(val, 0, sizeof(val));
	update(1, 0, n, 0, 1);
	for(int i = 1; i <= m; i++){
		int vv = query(1, 0, n, s[i], t[i] - 1);
		update(1, 0, n, t[i], vv);
	}
	cout<<query(1, 0, n, n, n)<<endl;
}