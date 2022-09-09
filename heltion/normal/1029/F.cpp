#include<bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > A, B;
int main(){
	long long a, b;
	scanf("%lld %lld", &a, &b);
	for(long long i = 1; i * i <= a; i += 1) if(a % i == 0){
		A.push_back(pair<long long, long long>(i, a / i));
	}
	for(long long i = 1; i * i <= b; i += 1) if(b % i == 0){
		B.push_back(pair<long long, long long>(i, b / i));
	}
	long long ans = 2 * (a + b + 1);
	for(long long i = 1; i * i <= a + b; i += 1) if((a + b) % i == 0){
		bool flag = false;
		for(auto p: A){
			if(p.first <= i && p.second <= (a + b) / i) flag = true;
		}
		for(auto p: B){
			if(p.first <= i && p.second <= (a + b) / i) flag = true;
		}
		if(flag) ans = min(ans, 2 * ((a + b) / i + i));
	}
	printf("%lld\n", ans);
}