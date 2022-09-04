#include<bits/stdc++.h>
#define time Time
#define pii pair<int,int>    
#define x first    
#define y second    
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))    
#define sqr(x) ((x)*(x))
typedef long long LL;  
using namespace std;
long long int input()   
{   
  char cha;   
  unsigned long long int x=0;   
  while(cha=getchar())   
     if(cha!=' '&&cha!='\n') break;   
  x=cha-48;   
  while(cha=getchar())    
    {   
     if(cha==' '||cha=='\n') break;   
      x=x*10+cha-48;   
    }   
    return x;   
}
vector<int> v[200005];
long long int a[200005];
long long int s[200005];
long long int dfs(int n,int f){
	long long int sum=a[n];
	for(int i=0;i<v[n].size();i++)
	 if(v[n][i]!=f)
	 sum+=dfs(v[n][i],n);
	 s[n]=sum;
	return sum;
}
long long int ans=-1e18;
long long int dfs2(int n,int f){
	long long int M=-1e18,M2=-1e18;
	for(int i=0;i<v[n].size();i++)
	if(v[n][i]!=f){
		long long int a=dfs2(v[n][i],n);
		if(a>M){
			M2=M;
			M=a;
		}
		else if(a>M2)
		M2=a;
	}
	if(M2!=-1e18){
		ans=max(ans,M+M2);
	}
	return max(M,s[n]);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%I64d",&a[i]);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1,0);
	dfs2(1,0);
	if(ans==-1e18)
	printf("Impossible\n");
	else
	printf("%I64d\n",ans);
}