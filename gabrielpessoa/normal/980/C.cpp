#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int SIZE = 105;

map<int, int> group;

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(!group.count(x)) {
			for(int i = max(0, x - k + 1); i <= x; i++) {
				if(!group.count(i)) {
					for(int j = i; j <= x; j++) {
						group[j] = i;
					}
				} else if(group[i] == i) {
					for(int j = i; j <= x; j++) {
						group[j] = i;
					}
				}
			}
		}
		cout << group[x] << ' ';
	}
	return 0;
}