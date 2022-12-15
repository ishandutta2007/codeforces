#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int ms = 2e5 + 5;

ll arr[4 * ms], segMax[4 * ms], segSum[4 * ms], n;

void build(int idx = 0, int l = 0, int r = n - 1) {
    int mid = (l+r)/2, left = 2 * idx + 1, right = 2 * idx + 2;
    if(l == r) {
        segMax[idx] = arr[l];
		segSum[idx] = arr[l];
        return;
    }
    build(left, l, mid); build(right, mid + 1, r);
    segSum[idx] = segSum[left] + segSum[right];
	segMax[idx] = max(segMax[left], segMax[right]);
}

ll querySum(int L, int R, int idx = 0, int l = 0, int r = n - 1) {
    int mid = (l+r)/2, left = 2 * idx + 1, right = 2 * idx + 2;
    if(R < l || L > r) return 0;
    if(L <= l && r <= R) return segSum[idx];
    return querySum(L, R, left, l, mid) + querySum(L, R, right, mid + 1, r);
}


int queryMax(ll val, int L, int R, int idx = 0, int l = 0, int r = n - 1) {
    int mid = (l+r)/2, left = 2 * idx + 1, right = 2 * idx + 2;    
	if(R < l || L > r || segMax[idx] < val) return n;
	if(L <= l && r <= R) {
		if(l == r) return l;
    	if(segMax[left] >= val) return queryMax(val, L, R, left, l, mid);
		else return queryMax(val, L, R, right, mid + 1, r);
	}
	int temp = queryMax(val, L, R, left, l, mid);
	if(temp < n) return temp;
	else return queryMax(val, L, R, right, mid + 1, r);
}

void update(ll V, int I, int idx = 0, int l = 0, int r = n -1) {
    int mid = (l+r)/2, left = 2 * idx + 1, right = 2 * idx + 2;
    if(l > I || r < I) return;
    if(l == r) {
        arr[I] = V;
        segMax[idx] = V;
		segSum[idx] = V;
        return;
    }
    update(V, I, left, l, mid); update(V, I, right, mid + 1, r);
    segSum[idx] = segSum[left] + segSum[right];
	segMax[idx] = max(segMax[left], segMax[right]);
}

int findKing() {
	ll idx = 0, sum = 0;
	while(idx < n) {
		if(sum == arr[idx]) return idx + 1;
		sum += arr[idx];
		//cout << "DBG idx - sum: " << idx << ' ' << sum << endl;
		idx = queryMax(sum, idx + 1, n - 1);
		sum = querySum(0, idx-1);
	}
	return -1;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int q;
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	build();
	while(q--) {
		int p;
		ll x;
		cin >> p >> x;
		update(x, p-1);
		//cout << "DBG posicao 0: " << querySum(0, 0) << ' ' << arr[0] << endl;
		cout << findKing() << '\n';
	}	
	return 0;
}