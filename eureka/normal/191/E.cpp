#include<iostream>
#include<cstring>
#include<set>
#include<map>
#include<cstdio>

using namespace std;

typedef long long lld;
lld lldmax = 1LL << 60;
const int N = 110000;
int a[N];
lld sum[N];
lld n, k;
map<lld, int> mp;

struct BIT{
	void init(int n){
		memset(a, 0, sizeof(a));
		this->n = n;
	}
	void update(int i, int b){
		while(i <= n){
			a[i] += b;
			i += i&(-i);
		}
	}
	int get(int i){
		int ans=0;
		while(i){
			ans += a[i];
			i &= i-1;
		}
		return ans;
	}
	void update(lld n){
		update(mp[n], 1);
	}
	int count(lld n){
		map<lld, int>::iterator it = mp.upper_bound(n);
		int id;
		if (it == mp.end()) id = N-1;
		else id = (--it)->second;
		return get(id);
	}
	int a[N], n;
}bit;

lld cal(lld num){
	bit.init(N-1);
	lld ans = 0;
	for (int i=1; i<=n; ++i){
		bit.update(sum[i-1]);
		ans += bit.count(sum[i] - num);
	}
	return ans;
}

int main(){
	cin >> n >> k;
	sum[0] = 0;
	for (int i=1; i<=n; ++i){
		scanf("%d", &a[i]);
		sum[i] = sum[i-1] + a[i];
		mp[sum[i]] = 0;
	}
	mp[0] = 0;
	mp[-lldmax] = 0;
	map<lld, int>::iterator it = mp.begin();
	for (int i=0; it!=mp.end(); ++i, ++it) it->second = i;
	lld l, r, m, ans;
	l = -lldmax, r = lldmax;
	while (l <= r){
		m = (l + r) / 2;
		if (cal(m) >= k){
			ans = m;
			l = m + 1;
		}else {
			r = m - 1;
		}
	}
	cout << ans << endl;
	return 0;
}