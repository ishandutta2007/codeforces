#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
char s[N],w[N];
void sol(){int x;
	scanf("%s%d",s+1,&x);
	int n=strlen(s+1);w[n+1]=0;
	rep(i,1,n)w[i]='1';
	rep(i,1,n)if(s[i]=='0'){
		if(i>x)w[i-x]='0';
		if(i+x<=n)w[i+x]='0';
	}
	rep(i,1,n)if(s[i]=='1'&&(i<=x||w[i-x]=='0')&&(i+x>n||w[i+x]=='0')){
		printf("-1\n");return;
	}
	printf("%s\n",w+1);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}