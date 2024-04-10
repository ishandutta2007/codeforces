#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int ms = 1e3+5, inf = 0x3f3f3f3f;
typedef long long ll;

int arr[ms];

int main(){
	int n, w;
	cin >> n >> w;
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 1; i < n; i++) arr[i] += arr[i-1];
	int menor = 0, maior = w;
	for(int i = 0; i < n; i++) {
		if(arr[i] > 0) {
			maior = min(maior, w - arr[i]);
		} else {
			menor = max(menor, -arr[i]);
		}
	}
	cout << max(0, maior - menor + 1) << '\n';
	return 0;
}