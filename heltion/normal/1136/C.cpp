#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 1000;
vector<int> A[maxn], B[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1){
			int x;
			cin >> x;
			A[i + j].push_back(x);
		}
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1){
			int x;
			cin >> x;
			B[i + j].push_back(x);
		}
	for(int i = 0; i < n + m; i += 1){
		sort(A[i].begin(), A[i].end());
		sort(B[i].begin(), B[i].end());
		for(int j = 0; j < A[i].size(); j += 1) if(A[i][j] != B[i][j]) no();
	}
	cout << "YES";
}