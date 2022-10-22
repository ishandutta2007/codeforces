#include <bits/stdc++.h>

using namespace std;

int n;
int po[100005];

int main(){
	cin >> n;
	if(n == 1){
		puts("YES");
		puts("1");
		return 0;
	}
	if(n == 2){
		puts("YES");
		puts("1");
		puts("2");
		return 0;
	}
	if(n == 4){
		puts("YES");
		printf("1\n3\n2\n4\n");
		return 0;
	}
	bool prime=1;
	for(int i=2; i*i <= n; ++i)
		if(n%i == 0)
			prime=0;
	if(!prime){
		puts("NO");
		return 0;
	}
	for(long long i=2; i < n; ++i){
		bool ok=1;
		int prod=1;
		for(int j=0; j < n-2; ++j){
			prod=(prod*i)%n;
			if(prod == 1){
				ok=0;
				break;
			}
		}
		if(!ok)
			continue;
		po[0]=1;
		for(int j=1; j <= n; ++j)
			po[j]=(po[j-1]*i)%n;
		puts("YES");
		int a=1, b=n-1;
		for(int j=0; 2*j+2 < n; ++j){
			printf("%d\n%d\n", po[b], po[a]);
			a += 2;
			b -= 2;
		}
		printf("%d\n", n);
		return 0;
	}
}