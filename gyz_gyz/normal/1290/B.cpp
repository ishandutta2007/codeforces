#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int mo=998244353;
char s[N];int v[N][26];
bool sol(int l,int r){
	if(l==r)return 1;
	int ct=0;
	rep(i,0,25)if(v[r][i]-v[l-1][i])++ct;
	if(ct>2)return 1;
	return s[l]!=s[r];
}
int main(){int m;
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,1,n){
		rep(j,0,25)v[i][j]=v[i-1][j]+(s[i]==j+'a');
	}
	scanf("%d",&m);
	rep(i,1,m){int l,r;
		scanf("%d%d",&l,&r);
		printf("%s\n",sol(l,r)?"Yes":"No");
	}
}