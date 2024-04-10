/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MOD=1e9+7;
int maze[2002][2002],row[2002][2002],colum[2002][2002];LL dp[2002][2002],from_left[2002][2002],from_up[2002][2002];
int main(){
	int n,m;
	cin>>n>>m;
	char tmp;
	rb(i,1,n)
		rb(j,1,m){
			cin>>tmp;
			maze[i][j]=(tmp=='R');
		}
	rb(i,1,n)
		rb(j,1,m) row[i][j]=row[i][j-1]+maze[i][j],colum[i][j]+=colum[i-1][j]+maze[i][j];
	dp[1][1]=1;
	rb(i,1,n)
	 	rb(j,1,m){
	 		if((i-1)||(j-1)){
	 			from_left[i][j]=dp[i][j-1];
	 			from_up[i][j]=dp[i-1][j];
	 			if(row[i][m]-maze[i][1]>=m-j+1){
	 			//	cout<<i<<" "<<j<<endl;
	 				int l,r=j-1;
	 				if(row[i][m]-maze[i][1]==m-j+1){
	 					l=0;
	 				}	
	 				else{
	 					int tl=1,tr=j;
	 					while(tl<tr-1){
	 						int mid=(tl+tr)>>1;
	 						if(row[i][m]-row[i][mid]>=m-j+2) tl=mid;
	 						else tr=mid;
	 					}
	 					l=tl;
	 				}
	 				l++;
	 				int tl=1,tr=j;
	 				while(tl<tr-1){
	 					int mid=(tl+tr)>>1;
	 					if(row[i][m]-row[i][mid]>=m-j+1) tl=mid;
	 					else tr=mid;
	 				}
	 				r=tl;
	 			//	cout<<l<<" "<<r<<endl;
	 				rb(k,l,r) {
					 	if(!(k-1)&&!(i-1)){
					 		from_left[i][j]+=MOD; 
					 		from_left[i][j]--;
					 		from_left[i][j]%=MOD;
					 	}
						else from_left[i][j]+=MOD,from_left[i][j]-=from_up[i][k],from_left[i][j]%=MOD;
					 }
				//	 cout<<from_left[i][j]<<endl;
	 			}
	 			if(colum[n][j]-maze[1][j]>=n-i+1){
	 				int l,r;
	 				if(colum[n][j]-maze[1][j]==n-i+1){
	 					l=0;
	 				}
	 				else{
	 					int tl=1,tr=i;
	 					while(tl<tr-1){
	 						int mid=(tl+tr)>>1;
	 						if(colum[n][j]-colum[mid][j]>=n-i+2) tl=mid;
	 						else tr=mid;
	 					}
	 					l=tl;
	 				}
	 				l++;
	 				int tl=1,tr=i;
	 				while(tl<tr-1){
	 					int mid=(tl+tr)>>1;
	 					if(colum[n][j]-colum[mid][j]>=n-i+1) tl=mid;
	 					else tr=mid;
					}r=tl;
					rb(k,l,r) {
						if(!(k-1)&&!(j-1)){
							from_up[i][j]+=MOD;
							from_up[i][j]--;
							from_up[i][j]%=MOD;
						}  
						else from_up[i][j]+=MOD,from_up[i][j]-=from_left[k][j],from_up[i][j]%=MOD;
//						cout<<"!"<<i<<" "<<j<<" - "<<k<<" "<<j<<endl;
					}
	 			}
	 			dp[i][j]=from_left[i][j]+from_up[i][j];
	 			dp[i][j]%=MOD;
	 		}
	 	}
//	cout<<from_left[3][3]<<" "<<from_up[3][3]<<endl;
//	cout<<dp[3][3]<<" "<<dp[3][2]<<" "<<dp[2][3]<<" "<<from_left[1][3]<<" "<<from_up[3][3]<<endl;
	cout<<dp[n][m]<<endl; 
	return 0;
}
/*
4 4
..R.
...R
R...
R...
Answer:12

3 4
..R.
...R
R...

3 5 
..R..
..RRR
.R...
Answer:0
*/