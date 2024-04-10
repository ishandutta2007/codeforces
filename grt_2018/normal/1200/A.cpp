#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 100*1000+10;
int n;
string s;
bool room[10];

int main() {_
	cin>>n>>s;
	for(auto it: s) {
		if(it=='L') {
			for(int i=0; i<10;i++) {
				if(room[i]==0) {
					room[i]=1; break;
				}
			}
		}
		else if(it=='R') {
			for(int i=9; i>=0;i--) {
				if(room[i]==0) {
					room[i]=1; break;
				}
			}
		}
		else {
			room[it-'0']=0;
		}
	}
	for(int i=0; i<10;i++) cout<<room[i];
}