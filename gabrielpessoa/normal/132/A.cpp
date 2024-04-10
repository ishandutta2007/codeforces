#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

int arr[105];

int main() {
	string s;
	getline(cin, s);
	for(int i = 0; i < s.length(); i++) {
		int reverso = s[i];
		//printf("%d\n", reverso);
		for(int j = 0; j < 8; j++) {
			arr[i] += ((reverso >> j) & 1) << (7-j);
		}
		//printf("%d\n", arr[i]);
	}
	printf("%d\n", 256 - arr[0]);
	for(int i = 1; i < s.length(); i++) {
		int resposta = arr[i-1] - arr[i];
		if(resposta < 0) {
			resposta += 256;
		}
		printf("%d\n", resposta);
	}
	return 0;
}