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


string last;
int found;

void Dfs(int x, int left, int flag, string s){
	if (x > last.size()){
		if (flag && left == 0){
			last = s;
			found = 1;
		}
		return;		
	}
	if (((int)last.size() - x + 1) * 9 < left) return;
	for (int i = 0; i < 10; i++){	
		if (i > left) continue;
		if (flag){
			Dfs(x + 1, left - i, flag, s + (char)('0' + i));
		}else{
			if (last[x - 1] - '0' == i) Dfs(x + 1, left - i, 0, s + (char)('0' + i));
			else if (last[x - 1] - '0' < i) Dfs(x + 1, left - i, 1, s + (char)('0' + i)); 
		}
		if (found) return;
	}
}
int main(){
	int n, x;
	last = "0";
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		found = 0;
		while (1){
			Dfs(1, x, 0, "");
			if (found) break;
			last = "0" + last;
		}
		cout << last << endl;
	}	
}