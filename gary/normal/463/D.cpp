//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,k;
int a[6][1001];
map<int,int> app[6];
vector<int> each[1001];
int dp[1001];
void solve(int now){
	if(dp[now]) return ;
	if(each[now].size()==0) {
		dp[now]=1;
		return;
	}
	int SZ=each[now].size();
	dp[now]=1;
	rb(i,0,SZ-1){
		if(!dp[each[now][i]]){
			solve(each[now][i]);
		}
		dp[now]=max(dp[each[now][i]]+1,dp[now]);
	}
	return;
}  
int main(){
	scanf("%d %d",&n,&k);
	rb(i,1,k)
		rb(j,1,n)
			scanf("%d",&a[i][j]),app[i][a[i][j]]=j;
	rb(i,1,n){
		rb(j,1,n){
			if(i==j) continue;
			int OK=1;
			rb(l,1,k){					
				if(app[l][i]<app[l][j]){
					OK=0;
				}
			}
			if(OK==1){
				each[i].PB(j);
//				cout<<i<<":"<<j<<endl;
			}
			
		}
	}
	int res=0;
	rb(i,1,n){
		solve(i);
		if(dp[i]>dp[res]) res=i;
	}
	printf("%d\n",dp[res]);
	return 0;
}