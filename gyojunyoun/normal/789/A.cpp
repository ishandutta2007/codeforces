#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define MAXN (100005)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int A[MAXN];
int N, K;
ll Ans;

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; i++) scanf("%d", &A[i]);
	for(int i = 0; i < N; i++) A[i] = (A[i]+K-1)/K;
	for(int i = 0; i < N; i++) Ans += A[i];
	cout << ((Ans+1)/2) << "\n";
	return 0;
}