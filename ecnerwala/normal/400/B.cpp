#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
char S[2000][2000];

int dist(int row) {
	int l = 0;
	while(S[row][l] != 'G') l++; 
	int r = 0;
	while(S[row][r] != 'S') r++;
	if(r < l) return -1;
	return r - l;
}

int D[2000];
int go() {
	for(int i = 0; i < N; i++) {
		D[i] = dist(i);
		if(D[i] < 0) return -1;
	}
	sort(D, D + N);
	return unique(D, D + N) - D;
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> S[i];
	cout << go() << '\n';
}