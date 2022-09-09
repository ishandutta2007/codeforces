//Author: Heltion
//Date: 09-17-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120000;
LL X[maxn], C[maxn], A, K;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n >> K;
	for(int i = 0; i < n; i += 1) cin >> X[i];
	cin >> A;
	for(int i = 0; i < n; i += 1) cin >> C[i];
	priority_queue<LL, vector<LL>, greater<LL>> q;
	LL ans = 0;
	for(int i = 0; i < n; i += 1){
		q.push(C[i]);
		while(K < X[i] and not q.empty()){
			ans += q.top();
			q.pop();
			K += A;
		}
		if(K < X[i]) no(-1);
	}
	cout << ans;
	return 0;
}