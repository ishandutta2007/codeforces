#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int>ve;
const int N=5e5+10;
const int inf=1e9;
int main(){int n;
	scanf("%d",&n);int mi=1e9,ct=0;
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(x<mi)mi=x,ct=0;
		else if(x==mi)++ct;
	}
	if(ct>=n/2&&ct<n)printf("Bob\n");else printf("Alice\n");
}