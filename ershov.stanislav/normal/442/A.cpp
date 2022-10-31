#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

bool t[5][5];
int n, res=100;

int main() {
	cin >> n;
	string s;
	for (int i=0; i<n; i++) {
		cin >> s;
		if (s[0]=='R') t[0][s[1]-'1']=true;
		if (s[0]=='G') t[1][s[1]-'1']=true;
		if (s[0]=='B') t[2][s[1]-'1']=true;
		if (s[0]=='Y') t[3][s[1]-'1']=true;
		if (s[0]=='W') t[4][s[1]-'1']=true;
	}
	for (int i=0; i<32; i++) for (int j=0; j<32; j++) {
		bool ans=true;
		for (int k1=0; k1<5; k1++) for (int k2=0; k2<5; k2++) for (int k3=0; k3<5; k3++) for (int k4=0; k4<5; k4++) {
			if ((k1==k3&&k2==k4)||!t[k1][k2]||!t[k3][k4]) continue;
			if (k1==k3||((((1<<k1)&i)==0)&&(((1<<k3)&i)==0))) {
				if (k2==k4||((((1<<k2)&j)==0)&&(((1<<k4)&j)==0))) {
					ans=false;
				}
			}
		}
		if (ans) {
			int a2=0;
			for (int k=0; k<5; k++) {
				if (i&(1<<k)) a2++;
				if (j&(1<<k)) a2++;
			}
			res=min(res, a2);
		}
	}
	cout << res;
    return 0;
}