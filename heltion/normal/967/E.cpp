#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x = 0;
	char c;
	do c = getchar();
	while(c < '0' or c >'9');
	do{
		x = x * 10 + c -'0';
		c = getchar();
	}while(c >= '0' and c <= '9');
	return x;
}
int log(LL x){
	LL p = 1;
	int c = 0;
	while(p << 1 <= x){
		 p <<= 1;
		 c += 1;
	}
	return c;
}
int main(){
	int n = read();
	LL *ans = new LL [n];
	vector<LL> a[64];
	for(int i = 0; i < n; i += 1){
		LL x = read();
		a[log(x)].push_back(x);
	}
	LL cur = 0;
	for(int i = 0; i < n; i += 1){
		bool flag = false;
		for(int j = 0; j < 64;  j += 1)
			if(a[j].empty() == false and (cur ^ a[j][a[j].size() - 1 ]) > cur){
				ans[i] = a[j][a[j].size() - 1];
				cur ^= a[j][a[j].size() - 1];
				a[j].pop_back();
				flag = true;
				break;
			}
		if(flag == false){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for(int i = 0; i < n; i += 1) printf("%lld ", ans[i]);
}