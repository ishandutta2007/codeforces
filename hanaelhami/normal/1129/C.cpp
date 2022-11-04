#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<r;i++)
#define put(x) cout<<#x<<" = "<<x<<endl;
#define X first
#define Y second
#define pb push_back
using namespace std;
typedef long long num;
const int maxn=3000+10,maxnode=maxn*maxn/2,M=1e9+7;

int n,ans[maxn],A[maxn];
bool mark[32];
int s[maxnode],ch[maxnode][2],last=1,dp[maxnode],par[maxnode];

struct Trie{
    void add(int a){
	int id=0;
	rep(i,a,n){
	    if(ch[id][A[i]]==0){
		ch[id][A[i]]=last;
		par[last]=id;
		s[last++]=i;
	    }
	    id=ch[id][A[i]];
	}
    }
    void dfs(int id,int h=0){
	dp[id]=(id==0);
	int t=min(4,h),a=id,b=1;
	rep(i,0,t){
	    b=b*2+A[s[a]];
	    a=par[a];
	    if(!mark[b]){
		dp[id]=(dp[id]+dp[a])%M;
	    }
	}
	ans[s[id]]=(ans[s[id]]+dp[id])%M;
	if(ch[id][0]!=0){
	    dfs(ch[id][0],h+1);
	}
	if(ch[id][1]!=0){
	    dfs(ch[id][1],h+1);
	}
    }
}trie;

int32_t main(){
    mark[31]=1;
    mark[23]=1;
    mark[26]=1;
    mark[28]=1;
    cin>>n;
    rep(i,0,n){
	cin>>A[i];
    }
    rep(i,0,n){
	trie.add(i);
    }
    trie.dfs(0);
    rep(i,1,n){
	ans[i]=(ans[i]+ans[i-1])%M;
    }
    rep(i,0,n){
	cout<<(ans[i]+M-1)%M<<endl;
    }
}