#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18;
char s[N];
void sol(){
	scanf("%s",s+1);
	int n=strlen(s+1),ans=0;
	rep(i,2,n)if(s[i]==s[i-2]||s[i]==s[i-1]){
		s[i]=0;++ans;
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}