#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
const int inf=1e9;
char s[N];
void sol(){int n;
	scanf("%d%s",&n,s+1);
	int nw=n+1,ls=0;
	rep(i,1,n)if(i==n||s[i]=='>'){
		dep(j,i-ls,1)printf("%d ",nw-j);
		nw-=i-ls;ls=i;
	}printf("\n");
	nw=0;ls=0;
	rep(i,1,n)if(i==n||s[i]=='<'){
		dep(j,i-ls,1)printf("%d ",nw+j);
		nw+=i-ls;ls=i;
	}printf("\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}