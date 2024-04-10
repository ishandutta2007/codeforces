#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

int perm[6][3]= {
	{0, 1, 2},
	{1, 2, 0},
	{2, 0, 1},
	{0, 2, 1},
	{2, 1, 0},
	{1, 0, 2},
};

long long v[8][3], vv[8][3], vv2[8][3];

bool check_ort(int i, int j) {
	long long sum=0;
	for (int k=0; k<3; k++) sum+=vv[i][k]*vv[j][k];
	return (sum);
}
bool is_there(int i, int j) {
	long long a, b, c;
	a=vv[i][0]+vv[j][0];
	b=vv[i][1]+vv[j][1];
	c=vv[i][2]+vv[j][2];
	for (int i=4; i<8; i++) {
		bool flag=true;
		if (vv[i][0]!=a) flag=false;
		if (vv[i][1]!=b) flag=false;
		if (vv[i][2]!=c) flag=false;
		if (flag) return true;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	for (int i=0; i<8; i++) for (int j=0; j<3; j++) cin >> v[i][j];
	for (int num=0; num<300000; num++) {
		int num2=num;
		for (int i=1; i<8; i++) {
			int cur=num2%6;
			for (int j=0; j<3; j++) vv[i][j]=v[i][perm[cur][j]]-v[0][j], vv2[i][j]=v[i][perm[cur][j]];
			num2/=6;
		}
		long long mind=1000000000000000000;
		for (int i=1; i<8; i++) mind=min(mind, vv[i][0]*vv[i][0]+vv[i][1]*vv[i][1]+vv[i][2]*vv[i][2]);
		if (mind==0) continue;
		else {
			for (int i=1, j=1; i<8; i++) {
				if (vv[i][0]*vv[i][0]+vv[i][1]*vv[i][1]+vv[i][2]*vv[i][2]==mind) {
					swap(vv[i][0], vv[j][0]);
					swap(vv[i][1], vv[j][1]);
					swap(vv[i][2], vv[j][2]);
					j++;
				}
			}
			if (check_ort(1, 2)) continue;
			if (check_ort(2, 3)) continue;
			if (check_ort(1, 3)) continue;
			if (!is_there(1, 2)) continue;
			if (!is_there(2, 3)) continue;
			if (!is_there(1, 3)) continue;
			bool flag=false;
			for (int i=4; i<8; i++) {
				bool flag2=true;
				for (int j=0; j<3; j++) if (vv[i][j]!=vv[1][j]+vv[2][j]+vv[3][j]) flag2=false;
				if (flag2) flag=true;
			}
			if (!flag) continue;
			cout << "YES" << endl;
			cout << v[0][0] << ' ' << v[0][1] << ' ' << v[0][2] << endl;
			for (int i=1; i<8; i++) {
				cout << vv2[i][0] << ' ' << vv2[i][1] << ' ' << vv2[i][2] << endl;
			}
			return 0;
		}
	}
	cout << "NO";
	return 0;
}