/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int mn[5005][5005];
int n,a[5005];
int dfs(int l,int r,int ok){
	if(l>r) return 0;
	int res=r-l+1;
	res=min(res,dfs(l,mn[l][r]-1,a[mn[l][r]])+a[mn[l][r]]-ok+dfs(mn[l][r]+1,r,a[mn[l][r]]));
	return res;
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n)
		cin>>a[i];
	rb(i,1,n){
		mn[i][i]=i;
		rb(j,i+1,n){
			mn[i][j]=mn[i][j-1];
			if(a[j]<a[mn[i][j]])
			{
				mn[i][j]=j;
			}
		}
	} 
//	cout<<mn[1][n]<<endl;
	cout<<dfs(1,n,0)<<endl;
	return 0;
}