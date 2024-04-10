#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

int T;
const int nax = 100*1000+10;
string x,y;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--) {
		cin>>x>>y;
		int cnt = 0;
		for(int i=y.size()-1; i>=0; i--) {
			if(y[i]=='0') cnt++;
			else break;
		}
		int pos = x.size()-1-cnt;
		while(pos>=0&&x[pos]=='0') pos--;
		cout<<x.size()-pos-1-cnt<<"\n";
	}
}