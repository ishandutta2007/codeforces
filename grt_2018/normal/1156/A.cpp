#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

int n;
int type[101];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
		cin>>type[i];
		if(i>0) {
			if(type[i]!=1&&type[i-1]!=1) {
				cout<<"Infinite";
				return 0;
			}
			if(max(type[i],type[i-1])==2) {
				ans+=3;
			}
			else {
				ans+=4;
			}
		}
		if(i>1) {
			if(type[i-2]==3&&type[i-1]==1&&type[i]==2) {
				ans--;
			}
		}
	}
	cout<<"Finite\n"<<ans;
}