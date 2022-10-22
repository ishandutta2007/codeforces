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

const int nax = 200*1000+10;
int q,n;
string A,B;
vi cntA,cntB;

int main() {_
	cin>>q;
	cntA.resize(26); cntB.resize(26);
	while(q--) {
		cin>>n>>A>>B;
		for(int i=0; i<26;i++) cntA[i]=cntB[i]=0;
		for(auto c:A) cntA[c-'a']++;
		for(auto c:B) cntB[c-'a']++;
		//for(int i=0; i<26; i++) {
		//	cout<<cntA[i]<<" "<<cntB[i]<<"\n";
		//}
		if(cntA!=cntB) {
			cout<<"NO\n";
			continue;
		}
		if(*max_element(cntA.begin(),cntA.end())>1) {
			cout<<"YES\n";
			continue;
		}
		int inv1=0,inv2=0;
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(A[i]>A[j]) inv1++;
				if(B[i]>B[j]) inv2++;
			}
		}
		if((inv1&1)==(inv2&1)) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}
		
		
		
	
}