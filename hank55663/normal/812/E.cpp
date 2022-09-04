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
vector<int> v[100005];
int dep[100005];
int dfs(int i){
	dep[i]=1;
	for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)
	{
		dep[i]=dfs(*it); 
	}
	return 1-dep[i];
} 
int aa[20000005][2];
int main(){
	int n;
	scanf("%d",&n);
	int a[100005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int p[100005];
	for(int i=1;i<n;i++){
		scanf("%d",&p[i]);
		p[i]--;
		v[p[i]].pb(i);
	}
	dfs(0);
	MEM(aa);
	int ans=0;
	int odd=0,even=0;
	for(int i=0;i<n;i++){
		aa[a[i]][dep[i]]++;
		if(dep[i]==1)
		ans^=a[i],odd++; 
		else
		even++;
	}
	if(ans==0){
		LL hi=0;
		hi=(LL)even*(even-1)/2+(LL)odd*(odd-1)/2;
		for(int i=0;i<=1e7;i++)
		hi+=(LL)aa[i][0]*aa[i][1];
		printf("%I64d\n",hi);
	}
	else{
		LL hi=0;
		for(int i=0;i<=1e7;i++)
		hi+=(LL)aa[i][0]*aa[ans^i][1];
		printf("%I64d\n",hi);
	}
}