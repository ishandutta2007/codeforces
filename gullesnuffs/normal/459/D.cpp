#include <bits/stdc++.h>

using namespace std;

int n, a[1000005];
map<int, int> occur;
int f0[1000005];
int f1[1000005];

struct Fenwick{
	int b[1000005];

	void update(int pos, int val){
		for(int i=pos; i < 1000005; i |= i+1)
			b[i] += val;
	}

	int query(int pos){
		int ret=0;
		for(int i=pos; i >= 0; i=(i&(i+1))-1)
			ret += b[i];
		return ret;
	}
} fenwick;

int main(){
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d", a+i);
		occur[a[i]]++;
		f0[i]=occur[a[i]];
	}
	occur.clear();
	for(int i=n-1; i >= 0; --i){
		occur[a[i]]++;
		f1[i]=occur[a[i]];
		fenwick.update(f1[i], 1);
	}
	long long ans=0;
	for(int i=0; i < n; ++i){
		fenwick.update(f1[i], -1);
		ans += fenwick.query(f0[i]-1);
		//fenwick.update(f0[i], 1);
	}
	printf("%I64d\n", ans);
}