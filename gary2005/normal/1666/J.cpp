#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=202;
LL dp[MAXN][MAXN];
int p[MAXN][MAXN];
LL c[MAXN][MAXN];
LL d[MAXN][MAXN][MAXN];
LL query(int l,int r,int x,int y){
	if(l>r||x>y) return 0;
	return d[l][r][y]-d[l][r][x-1];
}
int ans[MAXN];
int print(int l,int r){
	if(l>r) return 0;
	if(l==r) return l;
	int root=p[l][r];
	ans[print(l,root-1)]=root;
	ans[print(root+1,r)]=root;
	return root;
}
int main(){
	int n;
	cin>>n;
	rb(i,1,n) rb(j,1,n) cin>>c[i][j],c[i][j]+=c[i][j-1];
	rb(i,1,n) rb(j,i,n) rb(k,1,n){
		d[i][j][k]=d[i][j][k-1];
		d[i][j][k]+=c[k][j]-c[k][i-1];
	}
	rb(len,1,n){
		rb(l,1,n-len+1){
			int r=l+len-1;
			if(len==1) dp[l][r]=0;
			else{
				dp[l][r]=1e18;
				rb(j,l,r){
					LL val=dp[l][j-1]+dp[j+1][r]+query(l,j-1,j,n)+query(1,l-1,l,j-1)+query(j+1,r,1,j)+query(j+1,r,r+1,n);
					if(val<dp[l][r]){
						dp[l][r]=val;
						p[l][r]=j;
					}
				}
			}
		}
	}
	print(1,n);
//	cerr<<dp[1][4]<<endl;
	rb(i,1,n) cout<<ans[i]<<" ";
	cout<<endl;
    return 0;
}