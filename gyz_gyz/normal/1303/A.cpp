#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
char s[N];
void sol(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	int l=0,r=0,ct=0;
	rep(i,1,n)if(s[i]=='1'){
		if(!l)l=i;
		r=i;++ct;
	}
	printf("%d\n",!ct?0:r-l+1-ct);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}