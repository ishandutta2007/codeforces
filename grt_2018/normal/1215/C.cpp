#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int nax = 200*1000+10;
int n;
string s,t;
vi miss1,miss2;

int main() {_
	cin>>n>>s>>t;
	for(int i=0; i<n;i++) {
		if(s[i]!=t[i]) {
			if(s[i]=='a') miss1.PB(i+1);
			else miss2.PB(i+1);
		}
	}
	if(((int)miss1.size()+(int)miss2.size())%2==1) {
		cout<<"-1";
	} else {
		if((int)miss1.size()%2==0) {
			cout<<((int)miss1.size()+(int)miss2.size())/2<<"\n";
			for(int i=1; i<(int)miss1.size(); i+=2) {
				cout<<miss1[i]<<" "<<miss1[i-1]<<"\n";
			}
			for(int i=1; i<(int)miss2.size(); i+=2) {
				cout<<miss2[i]<<" "<<miss2[i-1]<<"\n";
			}
		} else {
			cout<<(int)miss1.size()/2+(int)miss2.size()/2+2<<"\n";
			for(int i=1; i<(int)miss1.size(); i+=2) {
				cout<<miss1[i]<<" "<<miss1[i-1]<<"\n";
			}
			for(int i=1; i<(int)miss2.size(); i+=2) {
				cout<<miss2[i]<<" "<<miss2[i-1]<<"\n";
			}
			cout<<miss1[miss1.size()-1]<<" "<<miss1[miss1.size()-1]<<"\n";
			cout<<miss1[miss1.size()-1]<<" "<<miss2[miss2.size()-1]<<"\n";
		}
	}
		
}