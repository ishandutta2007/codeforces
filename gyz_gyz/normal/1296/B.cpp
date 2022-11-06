#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int inf=1e9;
char s[N];
void sol(){
	int n,ans=0;
	scanf("%d",&n);
	for(;n>=10;n=n%10+n/10)ans+=n/10*10;
	printf("%d\n",ans+n);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}