/*
AuThOr Gwj
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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
struct Line
{
	LL k,b;
};
LL getval(Line from,LL x){
	return from.k*x+from.b;
} 
bool bad(Line A,Line B,Line C){
/*
y=kx+b   y=k1x+b1
kx+b=k1x+b1
(k-k1)x=b1-b
*/
	return (B.b-A.b)*(A.k-C.k)<(C.b-A.b)*(A.k-B.k);
}
LL d[100000+2],h[100000+2],t[100000+2],b[100000+2],n,m,p;LL dp[2][100000+2];
int main(){
	fastio;
	cin>>n>>m>>p;
	rb(i,2,n) cin>>d[i],d[i]+=d[i-1];
	rb(i,1,m)
	{
		cin>>h[i]>>t[i];
		h[i]=d[h[i]];
	}
	rb(i,1,m)
		b[i]=t[i]-h[i];
	sort(b+1,b+1+m);
	/*
	dp[now][j]= min{dp[from][k]-j*(b[k]-b[j])}(j<=k)
	dp[now][j]=min{dp[from][k]-j*b[k]+j*b[j]}
	dp[now][j]=min{dp[from][k]+(-j)*b[k]}+b[j]*j
	*/
	deque<Line> q;
	int prev=0,now=1;
	memset(dp[prev],127,sizeof(dp[prev]));
	dp[prev][m]=0;
	rb(i,1,m){
		dp[prev][m]+=b[m]-b[i];
	}
	Line tmp;
	rb(i,1,p-1){
		int x;
		q.clear();
		rl(j,m,1){
			x=-j;
			if(i!=1||j==m){
				tmp.b=dp[prev][j];
				tmp.k=b[j];
				if(!q.empty())
				if(q.back().k==tmp.k){
					tmp.b=min(tmp.b,q.back().b);
					q.pop_back();
				}
				while(q.size()>1&&bad(*(q.end()-2),tmp,*(q.end()-1))){
					q.pop_back();
				}
				q.push_back(tmp);	
			}
			while(q.size()>1&&getval(q.front(),x)>getval(*(q.begin()+1),x)){
				q.pop_front();
			}
			dp[now][j]=getval(q.front(),x)+(LL)b[j]*j;
		}
		swap(prev,now);	
	}
	LL res=dp[prev][1];
	rb(i,1,m){
		res=min(res,dp[prev][i]);
	}
	cout<<res<<endl;
	return 0;
}