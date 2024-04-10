/**
                      alex256                   
   
   Contest CodeForces Round 391                  
   
   Task    E                                     
   
   Date    12.01.2017                            
   **/
/// Global defines
#ifndef ONLINE_JUDGE
	#define LOCAL
#endif
//#define USE_LONGLONG
//#define USE_UNORDERED
//#define FILE_IO
//#undef LOCAL
#ifdef FILE_IO
	#define TASK_NAME "taskname"
	#define INPUT_FILE TASK_NAME".in"
	#define OUTPUT_FILE TASK_NAME".out"
#endif
/// Includes 
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

const int bufSize = 1 << 12;
const int mod = (int)1e9 + 7;

char buf[bufSize] = {};
int bufPos = bufSize;

inline char nextChar()
{
	if (bufPos == bufSize)
	{
		memset(buf, '\0', bufSize);
		fread(buf, sizeof(char), bufSize, stdin);
		bufPos = 0;
	}
	return buf[bufPos++];
}

inline int nextInt()
{
	char c = nextChar();
	while (c <= ' ') c = nextChar();
	int sign = +1, num = 0;
	if (c == '-' || c == '+')
	{
		sign = (c == '-') ? -1 : +1;
		c = nextChar();
	}
	while (c > ' ')
	{
		num = (num * 10) + c - '0';
		c = nextChar();
	}
	return num * sign;
}
/// End of The Template

const int maxNum = 1000000;

int divs[maxNum+1];
int dp[33], pdp[33];
int curLayer = 0;
int n = nextInt();
vector< pair< pair<int, int>, int > > queries(n);
vector<int> ans(n);

inline void nextLayer() {
	for (int i = 0; i <= 32; i++) {
		pdp[i] = dp[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= 32; i++) {
		dp[i] = pdp[i] + dp[i-1];
		if (dp[i] >= mod) {
			dp[i] -= mod;
		}
	}	
	curLayer++;
}

signed main() {
	dp[0] = 1;
	for (int i = 1; i <= 32; i++) {
		dp[i] = 2;
	}
	for (int i = 2; i <= maxNum; i++) {
		for (int j = i; j <= maxNum; j += i) {
			if (divs[j] == 0) {
				divs[j] = i;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		queries[i].F.F = nextInt();
		queries[i].F.S = nextInt();
		queries[i].S = i;
	}
	sort(queries.begin(), queries.end());
	for (int i = 0; i < n; i++) {	
		while (queries[i].F.F != curLayer) {
			nextLayer();
		}
		int res = 1;
		int cur = queries[i].F.S;
		while (cur != 1) {
			int curCnt = 0;
			int curDiv = divs[cur];
			while (cur % curDiv == 0) {
				cur /= curDiv;
				curCnt++;
			}
			res = ((long long)res * dp[curCnt]) % mod;
		}
		ans[queries[i].S] = res;
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}