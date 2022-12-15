#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int SIZE = 2E5 + 5;

ll tasks[SIZE];
vll um, dois;
ll total1, total2;

int main() {
	int n;
	scanf("%d", &n);
	bool ultimoPrimeiro = false;
	for(int i = 0; i < n; i++) {
		scanf("%lld", &tasks[i]);
		ultimoPrimeiro = tasks[i] > 0;
		if(tasks[i] > 0) {
			total1 += tasks[i];
			um.push_back(tasks[i]);
		} else {
			tasks[i] *= -1;
			total2 += tasks[i];
			dois.push_back(tasks[i]);
		}
	}
	if(total1 > total2) {
		puts("first");
	} else if(total2 > total1) {
		puts("second");
	} else {
		if(um > dois) {
			puts("first");
		} else if(dois > um) {
			puts("second");
		} else {
			if(ultimoPrimeiro) {
				puts("first");
			} else {
				puts("second");
			}
		}
	}
	return 0;
}