#include<iostream>
#include<cstring>
#include<cassert>

using namespace std;

typedef long long ll;

const int MAXN = 2e6;

int N;
char C[MAXN];
bool R[MAXN];

int curPos[MAXN];
int minPos[MAXN];

ll go() {
	for(int i = 0; i < N; i++) {
		R[i] = C[i] == C[N - 1];
	}

	curPos[0] = 0;
	minPos[0] = 0;
	for(int i = 0; i < N; i++) {
		if(R[i]) curPos[i + 1] = curPos[i] + 1;
		else curPos[i + 1] = curPos[i] - 1;
		minPos[i + 1] = min(minPos[i], curPos[i + 1]);
	}

	int len = curPos[N] - minPos[N];

	// can we do it with no obstacles
	bool good = true;
	for(int i = 0; i < N; i++) {
		if(curPos[i] >= curPos[N]) good = false;
	}

	if(good) return 1;

	good = true;

	//actual pos is curPos[i] - minPos[i] + max(minPos[i], obsPos)
	//moved actual pos is curPos[i] - min(obsPos, minPos[i]) < curPos[N] - minPos[N]
	//curPos[i] - obsPos < curPos[N] - minPos[N] && curPos[i] - minPos[i] < curPos[N] - minPos[N]
	
	for(int i = 0; i < N; i++) {
		if(curPos[i] - minPos[i] < curPos[N] - minPos[N]) ;
		else return 0;
	}
	int obsPos = -N - 1;
	for(int i = 0; i < N; i++) {
		obsPos = max(obsPos, curPos[i] - (curPos[N] - minPos[N]));
	}
	//cerr << obsPos << '\n';
	return -obsPos;
}

int main() {
	cin >> C;
	N = strlen(C);
	cout << go() << '\n';
	return 0;
}