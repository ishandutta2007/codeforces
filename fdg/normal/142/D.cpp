#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <ctime>
#include <cmath>

using namespace std;

char F[101][101]={0};

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,m,k,a[101]={0};
	cin >> n >> m >> k;
	for(int i=0;i<n;i++)
		cin >> F[i];
	bool loss=true;
	bool G=false,R=false;
	for(int i=0;i<n;i++) {
		int r=0,g=0,rp,gp;
		for(int j=0;j<m;j++)
		{
			if (F[i][j]=='R') r++,rp=j;
			if (F[i][j]=='G') g++,gp=j;
		}
		if (r==0&&g>0&&m!=g) G=true;
		else if (g==0&&r>0&&m!=r) R=true;
		else if (r&&g) a[i]=abs(rp-gp)-1;
	}
	if (G&&R) {
		cout << "Draw\n";
		return 0;
	}
	if (G) {
		cout << "First\n";
		return 0;
	}
	if (R) {
		cout << "Second\n";
		return 0;
	}
	for(int bit=0;bit<20;++bit) {
		int cnt=0;
		for(int i=0;i<n;i++)
			cnt+=(a[i]&(1<<bit))>0;
		if (cnt%(k+1)!=0) loss=false;
	}
	if (loss) cout << "Second\n";
	else cout << "First\n";
	return 0;
}