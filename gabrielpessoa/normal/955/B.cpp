#include <bits/stdc++.h>
using namespace std;

int arr[1000];

int main() {
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		arr[s[i]]++;
	}
	int qntD = 0;
	int qntMaior = 0;
	for(int i = 'a'; i <= 'z'; i++) {
		if(arr[i]) qntD++;
		if(arr[i] > 1) qntMaior++;
	}
	if(qntD == 4 || qntD == 3 && qntMaior >= 1 || qntD == 2 && qntMaior >= 2) {
		cout << "Yes\n";
	} else {
		cout << "No\n";	
	}
}