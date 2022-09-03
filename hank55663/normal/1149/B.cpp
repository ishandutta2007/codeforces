
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;
vector<int> v[26];
int next[26][100005];
int dp[255][255][255];
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	dp[0][0][0]=0;
	char c[100005];
	scanf("%s",c+1);
	int a[3]={0,0,0};
	for(int i =1;c[i]!=0;i++){
		v[c[i]-'a'].pb(i);
	}
	for(int i = 0;i<26;i++){
		for(int j=0;j<=n+1;j++){
			auto it=upper_bound(v[i].begin(),v[i].end(),j);
			if(it==v[i].end()){
				next[i][j]=n+1;
			}
			else{
				next[i][j]=*it;
			}
		}
	}
	vector<char> s[3];
	s[0].pb('a');
	s[1].pb('a');
	s[2].pb('a');
	while(q--){
		char c;
		scanf(" %c",&c);
		if(c=='+'){
			int x;
			char cc;
			scanf("%d %c",&x,&cc);
			x--;
			s[x].pb(cc);
			a[x]++;
			if(x==0){
				for(int i = 0;i<=a[1];i++){
					for(int j =0;j<=a[2];j++){
						int value=next[cc-'a'][dp[a[x]-1][i][j]];
						if(i!=0)
						value = min(value,next[s[1][i]-'a'][dp[a[x]][i-1][j]]);
						if(j!=0)
						value = min(value,next[s[2][j]-'a'][dp[a[x]][i][j-1]]);
						dp[a[x]][i][j]=value;
					}
				}
			}
			if(x==1){
				for(int i = 0;i<=a[0];i++){
					for(int j =0;j<=a[2];j++){
						int value=next[cc-'a'][dp[i][a[x]-1][j]];
						if(i!=0)
						value = min(value,next[s[0][i]-'a'][dp[i-1][a[x]][j]]);
						if(j!=0)
						value = min(value,next[s[2][j]-'a'][dp[i][a[x]][j-1]]);
						dp[i][a[x]][j]=value;
					//	printf("%d %d\n",i,dp[a[x]][i][j]);
					}
				}

			}
			if(x==2){
				for(int i = 0;i<=a[0];i++){
					for(int j =0;j<=a[1];j++){
						int value=next[cc-'a'][dp[i][j][a[x]-1]];
						if(i!=0)
						value = min(value,next[s[0][i]-'a'][dp[i-1][j][a[x]]]);
						if(j!=0)
						value = min(value,next[s[1][j]-'a'][dp[i][j-1][a[x]]]);
						dp[i][j][a[x]]=value;
					//	printf("%")
					//	printf("%d %d %d\n",i,j,dp[a[x]][i][j]);
					}
				}
			}
		}
		else{
			int x;
			scanf("%d",&x);
			x--;
			a[x]--;
			s[x].pop_back();
		}
		//printf("%d %d %d %d\n",a[0],a[1],a[2],dp[a[0]][a[1]][a[2]]);
		if(dp[a[0]][a[1]][a[2]]!=n+1){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}