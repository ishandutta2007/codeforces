#include<bits/stdc++.h>
#define maxn 1200000
using namespace std;
typedef long long LL;
int a[maxn];
vector<LL> v;
bool cmp(int n, int o){
	return v[n + 1] * v[n + 1] * v[o + 1] * v[o] + v[n] * v[n] * v[o] * v[o + 1]
		< v[o + 1] * v[o + 1] * v[n + 1] * v[n] + v[o] * v[o] * v[n] * v[n + 1];
}
int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t += 1){
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i += 1)
			scanf("%d", a + i);
		sort(a, a + n);
		int ans = 0;
		v.clear();
		for(int i = 0; i + 1 < n;){
			if(a[i] != a[i + 1]) i += 1;
			else{
				v.push_back((LL)a[i]);
				i += 2;
			}
		}
		for(int i = 1; i + 1 < v.size(); i += 1){
			if(cmp(i, ans)) ans = i;
		}
		printf("%lld %lld %lld %lld\n", v[ans], v[ans], v[ans + 1], v[ans + 1]);
	}
}