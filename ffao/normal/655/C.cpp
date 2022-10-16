#include <bits/stdc++.h>

 
using namespace std;


#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

char rooms[110000];
vector<int> fr;
int n,k;
void solve() {
	scanf("%d %d", &n, &k);
	scanf("%s", rooms);
	REP(i,n) if (rooms[i] == '0') fr.push_back(i);

	int a = 11000000;
	int farm = 0;
	for (int i = 0; i+k < (int)fr.size(); i++) {
		int st = fr[i];
		int ed = fr[i+k];
		while (farm < i+k && (farm < i || max(fr[farm+1]-st,ed-fr[farm+1]) <= max(fr[farm]-st,ed-fr[farm]))) farm++;
		a = min(a, max(fr[farm]-st,ed-fr[farm]));
	}

	printf("%d\n", a);
}

int main() {
    solve();
}