#include <bits/stdc++.h>
using namespace std;

long long a[100010];
map <long long, int> mp;

int Find(int x){
	if (!mp.count(x)) return 0;
	return mp[x];
}

int main(){
	int n;
	scanf("%d", &n);
	long long res = 0;
	for (int i = 0; i < n; i++){
		scanf("%I64d", &a[i]);
		for (long long j = 1; j <= (int)2e9; j <<= 1){
			res += Find(j - a[i]);
		}
		mp[a[i]]++;
	}
	printf("%I64d\n", res);
	return 0;
}