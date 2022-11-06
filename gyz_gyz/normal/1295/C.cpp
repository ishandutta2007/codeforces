#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
char s[N],t[N];int nt[N][26],v[26];
void sol(){
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	rep(i,0,25)v[i]=0;
	dep(i,n,0){
		rep(j,0,25)nt[i][j]=v[j];
		if(i)v[s[i]-'a']=i;
	}
	int ans=1,x=0;
	rep(i,1,m){
		if(!v[t[i]-'a'])return(void)printf("-1\n");
		if(!nt[x][t[i]-'a'])x=0,++ans;
		x=nt[x][t[i]-'a'];
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}