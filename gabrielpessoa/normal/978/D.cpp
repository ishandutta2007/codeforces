#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int ms = 2e5+5, inf = 0x3f3f3f3f;
typedef long long ll;

int arr[ms];
int temp[ms];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = inf;
	if(n <= 2) {
		cout << 0 << '\n';
		return 0;
	}
	for(int i = -1; i <= 1; i++) {
		for(int j = -1; j <= 1; j++) {
			int tempAns = abs(i) + abs(j);
			temp[0] = arr[0] + i;
			temp[1] = arr[1] + j;
			int dif = temp[1] - temp[0];
			for(int k = 2; k < n; k++) {
				if(arr[k] - temp[k-1] == dif) temp[k] = arr[k];
				else if(arr[k] - temp[k-1] == dif + 1) temp[k] = arr[k] - 1, tempAns++;
				else if(arr[k] - temp[k-1] == dif - 1) temp[k] = arr[k] + 1, tempAns++;
				else {
					tempAns = inf;
					break;
				}
			}
			ans = min(ans, tempAns);
		}
	}
	if(ans == inf) cout << "-1\n";
	else cout << ans << '\n';
	return 0;
}