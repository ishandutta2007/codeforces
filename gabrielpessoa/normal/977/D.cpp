#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int SIZE = 105;

vi g[SIZE];
ll arr[SIZE];
int entrada[SIZE];
bool vis[SIZE];

void dfs(int v) {
	cout << arr[v] << ' ';
	vis[v] = true;
	for(auto a : g[v]) {
		if(!vis[a]) dfs(a);
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(arr[i] == 3*arr[j]) {
				g[i].push_back(j);
				entrada[j]++;
			}
			if(arr[i] * 2 == arr[j]) {
				g[i].push_back(j);
				entrada[j]++;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(entrada[i] == 0) {
			dfs(i);
			break;
		}
	}
	return 0;
}