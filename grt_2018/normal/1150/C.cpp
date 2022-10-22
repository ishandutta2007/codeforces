#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 200*1000+1;
int n;
int cnt[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
		int x;
		cin>>x;
		cnt[x]++;
	}
	if(cnt[2]>0) {
		cout<<"2 ";
		cnt[2]--;
	}
	if(cnt[1]>0) {
		cout<<"1 ";
		cnt[1]--;
	}
	while(cnt[2]--) {
		cout<<"2 ";
	}
	while(cnt[1]--) {
		cout<<"1 ";
	}
	
}