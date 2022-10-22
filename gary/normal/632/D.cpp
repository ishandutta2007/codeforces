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
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m;
int final1,final2;
int dp[1000000+10];
vector<int> Dp[1000000+10];
int a[1000000+10];
int M[1000000+10];
int main(){
	final1=final2=-INF;
    scanf("%d %d",&n,&m);
    rb(i,1,n){
    	int ai;
    	scanf("%d",&ai);
		a[i]=ai;
    	if(ai>m) continue;
    	if(!M[ai])
    	for(int now=ai;now<=m;now+=ai){
    		Dp[now].PB(ai);
    	}
    	M[ai]++;
    }
    rb(i,1,m){
    	int SZ=Dp[i].size();
    	rep(j,SZ){
    		dp[i]+=M[Dp[i][j]];
    	}
    }
    rb(i,1,m){
    	if(dp[i]>final1){
    		final1=dp[i];
    		final2=i;
    	}
    }
    int res1=final2,res2=final1;
    printf("%d %d\n",res1,res2);
    rb(i,1,n){
    	if(res1%a[i]==0){
    		printf("%d ",i);
    	}
    }
	return 0;//
}