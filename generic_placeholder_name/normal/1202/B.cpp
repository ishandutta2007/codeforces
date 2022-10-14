#include <bits/stdc++.h>

#define ll long long

using namespace std;
int dist(char x, char y, int a, int b) {
	int m=x-48, n=y-48, max=1e9; 
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			if ((m+a*i+b*j)%10==n&&i+j<max&&i+j>0) max=i+j;
		}
	} 
	return max;
}

int main() {
	string s; cin>>s;
	int d[10][10][10][10];
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			for(int k=0; k<10; k++) {
				for(int l=0; l<10; l++) {
					d[i][j][k][l]=dist((char)i+48, (char)j+48, k, l);
				}
			}
		}
	}
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			ll cnt=0; bool possible=1;
			for(int k=0; k<s.length()-1; k++) {
				int tmp=d[(int)s[k]-48][(int)s[k+1]-48][i][j];
				if(tmp==1e9) {
					possible=0; break;
				} else cnt+=tmp-1;
			}
			cout<<(possible?cnt:-1)<<" ";
		}
		cout<<endl;
	}
}