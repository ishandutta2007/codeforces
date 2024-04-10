#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3010;
const ll inf=3e18;
const int mo=998244353;
char s[N],t[N];
int f[N][N];
int main(){
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	rep(i,1,n)if(i>m||s[1]==t[i])f[1][i]=2;
	int ans=0;
	if(m==1)ans=f[1][1];
	rep(i,2,n){
		rep(j,1,n){
			if(j>1&&(j-1>m||s[i]==t[j-1]))(f[i][j-1]+=f[i-1][j])%=mo;
			if(j+i-1<=n&&(j+i-1>m||s[i]==t[j+i-1]))(f[i][j]+=f[i-1][j])%=mo;
		}
		if(i>=m)(ans+=f[i][1])%=mo;
	}
	printf("%d\n",ans);
}