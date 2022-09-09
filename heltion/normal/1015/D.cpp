#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n, k, s;
	scanf("%lld %lld %lld", &n, &k, &s);
	if(k > s || k * (n - 1) < s){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for(long long pos = 1; k; k -= 1){
		if(k + n - 2 < s){
			if(pos == 1) pos = n;
			else pos = 1;
			s -= n - 1;
		}
		else if(k == s){
			if(pos == 1) pos += 1;
			else pos -= 1;
			s -= 1;
		}
		else{
			if(pos == 1) pos += s - k + 1;
			else pos -= s - k + 1;
			s = k - 1;
		}
		printf("%lld ", pos);
	}
}