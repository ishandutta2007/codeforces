#include <bits/stdc++.h>

using namespace std;

vector<int> a[2];

int main(){
	int n;
	scanf("%d", &n);
	bool advantage=0;
	long long sum=0;
	for(int i=0; i < n; ++i){
		int A;
		scanf("%d", &A);
		sum += A;
		if(A > 0){
			a[0].push_back(A);
			advantage=0;
		}
		else{
			a[1].push_back(-A);
			advantage=1;
		}
	}
	if(sum > 0)
		puts("first");
	else if(sum < 0)
		puts("second");
	else{
		for(int i=0; i < a[0].size(); ++i){
			if(a[0][i] > a[1][i]){
				puts("first");
				return 0;
			}
			if(a[1][i] > a[0][i]){
				puts("second");
				return 0;
			}
		}
		if(advantage)
			puts("second");
		else
			puts("first");
	}
}