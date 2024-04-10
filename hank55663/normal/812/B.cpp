#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
char c[20][105];
int ans=1e9;
int n,m,k;
void dfs(int i,int s,int sum){
//	printf("%d %d %d\n",i,s,sum);
	if(i==k){
		int a=0;
		for(int j=0;c[i][j]!=0;j++) 
		if(c[i][j]=='1'){
			if(s==0)
			a=j;
			else{
					a=max(a,m+2-j-1);
			}
		}
		ans=min(sum+a,ans);
		return;
	}
	dfs(i-1,1-s,sum+m+2);
	int a=0;
	for(int j=0;c[i][j]!=0;j++)
	if(c[i][j]=='1'){
		if(s==0)
		a=j;
		else{
			a=max(a,m+2-j-1);
		}
	}
	dfs(i-1,s,sum+a*2+1);
}
int main(){
	scanf("%d %d",&n,&m);
	k=0;
	int cc=1;
	for(int i=0;i<n;i++){
		scanf("%s",c[i]);
		if(cc){
			int ok=1;
			for(int j=0;c[i][j]!=0;j++)
			if(c[i][j]=='1')
			ok=0;
			if(ok)
			k++;
			else
			cc=0;
		}
	}
	if(k==n)
	printf("0\n");
	else{
	dfs(n-1,0,0);
	printf("%d\n",ans);
	}
}