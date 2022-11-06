#include<bits/stdc++.h>
#define maxn 240000
using namespace std;
typedef long long LL;
int c[maxn];
int a[maxn];
bool vis[maxn];
vector<int> v;
set<int> s;
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i += 1) scanf("%d", c + i);
	for(int i = 1; i <= n; i += 1) scanf("%d", a + i);
	for(int i = 1; i <= n; i += 1) if(vis[i] == false){
		s.clear();
		for(int p = i; ; p = a[p]){
			if(vis[p] == true){
				if(s.count(p))v.push_back(p);
				break;
			}
			vis[p] = true;
			s.insert(p);
		}
	}
	long long ans = 0;
	for(int x: v){
		//printf("%d\n", x);
		int pans = c[x];
		for(int p = a[x]; p != x; p = a[p]) pans = min(pans, c[p]);
		ans += pans;
	}
	printf("%lld", ans);
}