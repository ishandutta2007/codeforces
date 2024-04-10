#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 1000+10;
int n,m;
bool used[nax];
vector<pii>V;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int a,b,c,i=0; i<m;i++) {
		cin>>a>>b>>c;
		if(a==1) {
			b++;
			for(int j=b; j<=c;j++) used[j]=1;
		}
		else {
			V.PB({b,c});
		}
	}
	for(auto it:V) {
		bool ok = 0;
		for(int i=it.ST+1; i<=it.ND;i++) {
			ok|=(!used[i]);
		}
		if(!ok) {
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES\n";
	int id = 1000*1000*1000;
	for(int i=1; i<=n;i++) {
		if(!used[i]) id--;
		cout<<id<<" ";
	}
}