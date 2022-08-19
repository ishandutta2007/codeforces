/*
ID: he.andr1
PROG: 274A
LANG: C++
*/

#include<cstdio>
#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 100010;
int N;
ll K, A[MAXN];

int go() {
	int out = 0;
	sort(A, A + N);
	queue<ll> q;
	for(int i = 0; i < N; i++) {
		ll a = A[i];
		while(!q.empty() && q.front() < a) q.pop();
		if(q.empty() || q.front() != a) {
			out++;
			q.push(a * K);
		}
	}
	return out;
}

void io() {
	cin >> N >> K;
	for(int i = 0; i < N; i++) cin >> A[i];
	cout << go() << '\n';
}

int main(){
	io();
	return 0;
}