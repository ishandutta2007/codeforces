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


int cnt[255], v[200005], A, B;
string s, t;
int main(){
	cin >> s >> t;
	for (int i = 0; i < t.size(); i++)
		cnt[t[i]]++;
	for (int i = 0; i < s.size(); i++)
	if (s[i] >= 'a' && s[i] <= 'z'){
		if (cnt[s[i]]){
			cnt[s[i]]--;
			A++;
			v[i] = 1;
		}
	}else{
		if (cnt[s[i]]){
			cnt[s[i]]--;
			A++;
			v[i] = 1;
		}
	}
	for (int i = 0; i < s.size(); i++)
	if (!v[i]){
		if (s[i] >= 'a' && s[i] <= 'z'){
			if (cnt[s[i] - 'a' + 'A']){
				cnt[s[i] - 'a' + 'A']--;
				B++;
			}
		}else if (cnt[s[i] - 'A' + 'a']){
			cnt[s[i] - 'A' + 'a']--;
			B++;
		}
	}
	printf("%d %d\n", A, B);
	
}