#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m;
char c[9][9];
bool b[9][9];
const int z=9;
const int w=3;
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	b[0][0]=true;
	b[3][1]=true;
	b[6][2]=true;
	b[1][3]=true;
	b[4][4]=true;
	b[7][5]=true;
	b[2][6]=true;
	b[5][7]=true;
	b[8][8]=true;
	while(t--){
		for(int i=0; i<9 ;i++){
			for(int j=0; j<9 ;j++){
				cin >> c[i][j];
				if(b[i][j]){
					c[i][j]++;
					if(c[i][j]>'9') c[i][j]='1';
				}
			}
		}
		for(int i=0; i<9 ;i++){
			for(int j=0; j<9 ;j++){
				cout << c[i][j];
			}
			cout << '\n';
		}
	}
}