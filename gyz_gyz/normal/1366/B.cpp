#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=1e6+10;
const int inf=1e9;
const int mo=1e9+7;
void sol(){int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	int ml=k,mr=k;
	rep(i,1,m){int l,r;
		scanf("%d%d",&l,&r);
		if(l<=mr&&r>=ml)ml=min(ml,l),mr=max(mr,r);
	}
	printf("%d\n",mr-ml+1);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}