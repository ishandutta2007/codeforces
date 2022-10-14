/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(register  int a=b;a<=c;++a)
#define rl(a,b,c) for(register  int a=b;a>=c;--a)
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
int n,m,q,a[505][505],dp[505][505][4],oo[505];int sum[505][505][505];//ijk;
/*
0 1 
2 3
R->0
G->1
Y->2
B->3
*/
inline int query(int r1,int c1,int r2,int c2,int col){
	if(c2<c1||r2<r1) return 0;
	return max(0,sum[r2][c2][col]-sum[r1-1][c2][col]-sum[r2][c1-1][col]+sum[r1-1][c1-1][col]);
}
int main(){
	fastio;
	cin>>n>>m>>q;
//	memset(dp,63,sizeof(dp));
	memset(a,63,sizeof(a));
	rb(i,1,n)
		rb(j,1,m){
			char c;
			cin>>c;
			int key;
			if(c=='R')
				key=0;
			if(c=='G')
				key=1;
			if(c=='Y')
				key=2;
			if(c=='B')
				key=3;
			a[i][j]=key;
//			cout<<a[i][j]<<" ";
//			if(j==m){
//				cout<<endl;
//			}
		}
	//0
	rb(i,1,n)
		rb(j,1,m)
			{
//				cout<<i<<" "<<j<<endl;
				int A,B,C;
				A=B=0;
				C=dp[i-1][j-1][0];
				C++;
				for(int k=i;;k--)
					if(a[k][j]==0) B++;
					else break;
				for(int k=j;;k--)
					if(a[i][k]==0) A++;
					else break;
				dp[i][j][0]=min(A,min(C,B));
			 }//cout<<"!\n";
	//1 
//	cout<<"!!"<<endl; 
	rb(i,1,n)
		rl(j,m,1)
		{
			int A,B,C;
			A=B=0;
			C=dp[i-1][j+1][1];
			C++;
			for(int k=i;;k--)
					if(a[k][j]==1) B++;
					else break;
			for(int k=j;;k++)
					if(a[i][k]==1) A++;
					else break;
			dp[i][j][1]=min(A,min(B,C));
		}
	//2 
//	cout<<"!!!"<<endl;
	rl(i,n,1)
		rb(j,1,m)
			{
				int A,B,C;
				A=B=0;
				C=dp[i+1][j-1][2];
				C++;
				for(int k=i;;k++)
				{
					if(a[k][j]==2){
						B++;
					}
					else break;
				}
				for(int k=j;;k--){
					if(a[i][k]==2){
						A++;
					}
					else break;
				}
				dp[i][j][2]=min(A,min(B,C));
			 } 
	// 
	rl(i,n,1)
		rl(j,m,1)
		{
			int A,B,C;
			A=B=0;
			C=dp[i+1][j+1][3]+1;
			for(int k=i;;k++){
				if(a[k][j]==3) A++;
				else break;	
			}
			for(int k=j;;k++)
				if(a[i][k]==3) B++;
				else break;
			dp[i][j][3]=min(A,min(B,C));
		 } 
	
	rb(i,1,n)
		rb(j,1,m)
			{
				int M=min(min(dp[i][j][0],dp[i][j+1][1]),min(dp[i+1][j][2],dp[i+1][j+1][3]))*2;
				int x,y;
				x=i-(M>>1)+1;
				y=j-(M>>1)+1;
				for(int is=M;is;is-=2,x++,y++){
					oo[is]=1;
					sum[x][y][is]=1;
				} 
			}
	rb(k,1,504){
		if(oo[k])
		rb(i,1,n-k+1)
		rb(j,1,m-k+1){
			sum[i][j][k]+=sum[i-1][j][k]+sum[i][j-1][k]-sum[i-1][j-1][k];
		}
	}
	while(q--){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		int l=0,r=(n>>1)+1;
		while(l<r-1){
			int mid=(l+r)>>1;
			int i=mid<<1; 
			int x2,y2;
			x2=r2-i+1;
			y2=c2-i+1;
			if(query(r1,c1,x2,y2,i)){
				l=mid;
			}
			else
			{
				r=mid;
			}
		}
		l<<=1;
		cout<<l*l<<endl;
	}
	return 0;
}