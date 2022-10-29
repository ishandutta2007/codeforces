#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, LL> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int cnt[1111111], a[111111], n;
vector <int> v;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n); reverse(a, a + n);
	for (int i = 0; i < n; i++){
		if (cnt[a[i] + 1]){
			cnt[a[i] + 1]--;
			v.push_back(a[i]);
		}else if (cnt[a[i]]){
			cnt[a[i]]--;
			v.push_back(a[i]);
		}else cnt[a[i]]++;
	}	
	sort(v.begin(), v.end()); reverse(v.begin(), v.end());
	long long ans = 0;
	for (int i = 1; i < v.size(); i += 2)
		ans += (long long)v[i] * v[i - 1];
	printf("%I64d\n", ans);
}