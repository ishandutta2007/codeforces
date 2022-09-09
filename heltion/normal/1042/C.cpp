#include<bits/stdc++.h>
#define maxn 240000
using namespace std;
typedef long long LL;
set<int> zr, ne, all;
LL a[maxn];
int out(set<int> &re){
	if(re.empty()) return 0;
	int p = *re.begin();
	re.erase(p);
	while(re.empty() == false){
		int q = *re.begin();
		printf("1 %d %d\n", p, q);
		re.erase(q);
		p = q;
	}
	return p;
}
int main(){
	int n, p, q;
	scanf("%d", &n);
	for(int i = 1; i <= n; i += 1){
		scanf("%lld", a + i);
		if(a[i] == 0) zr.insert(i);
		if(a[i] < 0) ne.insert(i);
		if(a[i] != 0) all.insert(i);
	}
	a[p = 0] = - 1E9 - 7;
	for(int i = 1; i <= n; i += 1)
		if(a[i] < 0 && a[i] > a[p]) p = i;
	if(ne.size() % 2){
		all.erase(p);
		if(zr.empty() == false){
			q = out(zr);
			printf("1 %d %d\n", q, p);
		}
		if(all.empty() == false) printf("2 %d\n", p);
		out(all);
	}
	else{
		if(zr.empty() == false){
			q = out(zr);
			if(all.empty() == false) printf("2 %d\n", q);
		}
		out(all);
	}
}