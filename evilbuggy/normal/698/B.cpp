#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int a[N], vis[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int root = -1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == i)root = i;
	}
	int answer = 0;
	if(root == -1){
		int x = 1;
		set<int> st;
		while(!st.count(x)){
			st.insert(x);
			x = a[x];
		}
		a[x] = root = x;
		answer++;
	}
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++){
		if(vis[i])continue;
		int x = i;
		while(true){
			if(x != root && vis[x] == 0){
				vis[x] = i;
				x = a[x];
			}else{
				if(vis[x] == i){
					a[x] = root;
					answer++;
				}
				break;
			}
		}
	}
	cout << answer << '\n';
	for(int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	cout << '\n';

	return 0;
}