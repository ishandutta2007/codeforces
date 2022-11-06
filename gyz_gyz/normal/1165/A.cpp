#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll Inf=1e18;
char s[N];
int main(){int n,x,y,ans=0;
	scanf("%d%d%d",&n,&x,&y);
	scanf("%s",s+1);
	rep(i,n-x+1,n)if(s[i]!='0'+(i==n-y))++ans;
	printf("%d\n",ans);
}