#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int inf=1e9;
char s[N];
void sol(){int n;
	scanf("%d",&n);
	map<pii,int>a;
	scanf("%s",s+1);
	pii nw;a[nw]=0;int an1=-1,an2=n;
	rep(i,1,n){
		if(s[i]=='L')--nw.first;
		if(s[i]=='R')++nw.first;
		if(s[i]=='U')--nw.second;
		if(s[i]=='D')++nw.second;
		if(a.count(nw)){int x=a[nw];
			if(i-x<an2-an1+1)an1=x+1,an2=i;
		}
		a[nw]=i;
	}
	if(~an1)printf("%d %d\n",an1,an2);
	else printf("-1\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}