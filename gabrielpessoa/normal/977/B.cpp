#include<bits/stdc++.h>
using namespace std;

int arr[1000];

int main(){
	int n;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n - 1; i++) {
		int hash = s[i] - 'A' + (s[i+1] - 'A' )* (26);
		arr[hash]++;
	}
	int maior = 0;
	for(int i = 1; i < 26*26; i++) {
		if(arr[i] > arr[maior]) maior = i;
	}
	cout << (char) (maior % 26 + 'A') << (char) ( maior / 26 + 'A') << '\n';
	return 0;
}