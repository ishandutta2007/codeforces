#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 200005;
int a[N], b[N], l[N], r[N], tr[4*N];

void push(int v){
	if(tr[v]){
		tr[2*v] = tr[v];
		tr[2*v + 1] = tr[v];
		tr[v] = 0;
	}
}

void update(int v, int s, int e, int lo, int hi, int val){
	if(lo <= s && e <= hi){
		tr[v] = val;
		return;
	}
	push(v);
	int m = (s + e)/2;
	if(lo <= m)update(2*v, s, m, lo, hi, val);
	if(m < hi)update(2*v + 1, m + 1, e, lo, hi, val);
}

int query(int v, int s, int e, int ind){
	if(s == e)return tr[v];
	push(v);
	int m = (s + e)/2;
	if(ind <= m)return query(2*v, s, m, ind);
	return query(2*v + 1, m + 1, e, ind);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, q;
	cin>>n>>q;
	int zp = -1;
	memset(l, -1, sizeof(l));
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(a[i] != 0){
			if(l[a[i]] == -1)l[a[i]] = i;
			r[a[i]] = i;
		}else{
			zp = i;
		}
	}
	if(l[q] == -1){
		if(zp == -1){
			cout<<"NO"<<endl;
			exit(0);
		}
		l[q] = r[q] = zp;
	}
	for(int i = q - 1; i > 0; i--){
		if(l[i] == -1){
			l[i] = l[i + 1];
			r[i] = r[i + 1];
		}else if(l[i + 1] <= l[i] && r[i] <= r[i + 1]){
			cout<<"NO"<<endl;
			exit(0);
		}
	}
	// for(int i = 1; i <= q; i++){
	// 	cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
	// }
	memset(tr, 0, sizeof(tr));
	for(int i = 1; i <= q; i++){
		update(1, 1, n, l[i], r[i], i);
	}
	for(int i = 1; i <= n; i++){
		b[i] = query(1, 1, n, i);
		// cout<<b[i]<<" ";
	}
	for(int i = 1; i < n; i++){
		if(!b[i + 1])b[i + 1] = b[i];
	}
	for(int i = n; i > 1; i--){
		if(!b[i - 1])b[i - 1] = b[i];
	}

	for(int i = 1; i <= n; i++){
		if(a[i] && a[i] != b[i]){
			cout<<"NO"<<endl;
			exit(0);
		}
	}
	cout<<"YES"<<endl;
	for(int i = 1; i <= n; i++){
		cout<<b[i]<<" ";
	}

	return 0;
}