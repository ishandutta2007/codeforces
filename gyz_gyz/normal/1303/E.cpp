#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e3+10;
const int mo=1e9+7;
char s[N],t[N];int f[N][N];
void sol(){
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	rep(i,1,m){
		rep(j,0,n)rep(k,0,min(j,i))f[j][k]=-1;
		f[0][0]=i;
		rep(j,0,n-1)rep(k,0,min(j,i)){
			if(k<i&&s[j+1]==t[k+1])f[j+1][k+1]=max(f[j+1][k+1],f[j][k]);
			if(f[j][k]<m&&s[j+1]==t[f[j][k]+1])f[j+1][k]=max(f[j+1][k],f[j][k]+1);
			else f[j+1][k]=max(f[j+1][k],f[j][k]);
		}
		if(f[n][i]==m){
			printf("YES\n");return;
		}
	}
	printf("NO\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}