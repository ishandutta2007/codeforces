#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int ms = 55;

int arr[ms];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int c = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(arr[i] == arr[j]) {
				c++;
				arr[i] = -1;
				break;
			}
		}
	}
	cout << n - c << '\n';
	for(int i = 0; i < n; i++) {
		if(~arr[i]) cout << arr[i] << ' ';
	}
	return 0;
}