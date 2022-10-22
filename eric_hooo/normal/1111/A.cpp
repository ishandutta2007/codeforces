#include <bits/stdc++.h>
using namespace std;

int can(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
	string a, b;
	cin >> a >> b;
	if (a.size() != b.size()){
		printf("No\n");
		return 0;
	}
	for (int i = 0; i < min(a.size(), b.size()); i++){
		if (can(a[i]) != can(b[i])){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}