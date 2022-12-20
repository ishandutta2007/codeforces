#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<iostream>
#include<cmath>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back

const int N = 110000;
int a[N];
int ans[N], top;
int n;

inline bool check(int a, int n){
	return (a >> n) & 1;
}

bool judge(int m){
	int mask = (1LL << m) - 1;
	int sum = mask;
	top = 0;
	for (int i=0; i<n; ++i){
		if (check(a[i], m)){
			ans[top] = a[i];
			top ++;
			sum &= mask & a[i];
		}
	}
	return top > 0 && sum == 0;
}

int main(){
	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	for (int i=30; i>=0; --i){
		if (judge(i)){
			printf("%d\n", top);
			for (int j=0; j<top; ++j) printf("%d ", ans[j]);
			puts("");
			return 0;
		}
	}
}