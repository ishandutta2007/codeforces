#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 50 + 10;
class AbstactSolver
{
public:
	virtual void outputGuess() = 0;
	virtual void getResult() = 0;
	virtual void outputFinalResult() = 0;
	void check(vector<int> &v, char o)
	{
		while (v.size() > 1)
		{
			for (int i = 1; i < v.size(); i += 2)
			{
				gx = v[i];
				gy = v[i - 1];
				outputGuess();
				getResult();
				if (response[0] == o) v[i - 1] = 0;
				else v[i] = 0;
			}
			sort(v.rbegin(), v.rend());
			while (v.back() == 0) v.pop_back();
		}
	}
	void solve()
	{
		scanf("%d", &n);
		vector<int> maxv, minv;
		for (int i = 2; i <= n; i += 2)
		{
			gx = i - 1;
			gy = i;
			outputGuess();
			getResult();
			if (response[0] == '>') maxv.push_back(gx), minv.push_back(gy);
			else maxv.push_back(gy), minv.push_back(gx);
		}
		if (n & 1) maxv.push_back(n), minv.push_back(n);
		check(maxv, '>');
		check(minv, '<');
		
		
		// 
		gx = minv[0];
		gy = maxv[0];
		outputFinalResult();
	}
public:
	int n;
	int gx, gy;
	int a[N]; // 
	char response[10]; // 
};

// LocalSolve
class LocalSolver : public AbstactSolver
{
public:
	int cx, cy; // 
	int guessCount; // 
	int maxvGuss;
public:
	LocalSolver()
	{
		guessCount = 0;
		// 
		n = 3;
		maxvGuss = (3 * n + 1) / 2 - 2;

		srand(0);
		cx = INF;
		cy = 0;
		for (int i = 1; i <= n; i++)
		{
			a[i] = rand() % INF;
			if (a[i] < 0) a[i] = INF;
			cx = min(cx, a[i]);
			cy = max(cy, a[i]);
		}
		
	}
	void outputGuess()
	{
		// 
		printf("the %d round, you guess the number is: %d %d\n", ++guessCount, gx, gy);
	}

	void getResult()
	{
		// 
		response[1] = 0;
		if (a[gx] > a[gy]) response[0] = '>';
		if (a[gx] == a[gy]) response[0] = '=';
		if (a[gx] < a[gy]) response[0] = '<';
		///*if (dis(gx, gy) >= pre)*/ response = 0;
		///*else*/ response = 1;
		//pre = dis(gx, gy);
		printf("the %d round, the feedback is:\n%s\n\n", guessCount, response);
	}

	bool isGuessCorrect()
	{
		for (int i = 1; i <= n; i++) if (a[gx] > a[i]) return false;
		for (int i = 1; i <= n; i++) if (a[gy] < a[i]) return false;
		return true;
	}
	void outputFinalResult()
	{

		printf("\nYou guess the number is: %d %d\n,", a[gx], a[gy]);
		printf("The correct Number is: %d %d\n", cx, cy);
		printf("your guess is %s\n", isGuessCorrect() ? "TRUE" : "FALSE");
		printf("total guess count is: %d, The maximum guess count is %d\n", guessCount, maxvGuss);
	}

};

class RemoteSolver : public AbstactSolver
{
public:
	void outputGuess()
	{
		printf("? %d %d\n", gx, gy);
		fflush(stdout);
	}
	void getResult()
	{
		scanf("%s", response);
	}
	void outputFinalResult()
	{
		printf("! %d %d\n", gx, gy);
		fflush(stdout);
	}
};
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	RemoteSolver solver;
	//LocalSolver solver;
	int ncase;
	scanf("%d", &ncase);
	while (ncase--) solver.solve();
	return 0;
}