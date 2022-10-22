#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define ST first
#define ND second

const int nax = 100*1000+10;
int n;
int deg[nax];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	for(int a,b, i=1; i<n;i++) {
        cin>>a>>b;
        deg[a]++; deg[b]++;
	}
	for(int i=1; i<=n;i++) {
        if(deg[i]==2) {
            cout<<"NO";
            return 0;
        }
	}
	cout<<"YES";
}