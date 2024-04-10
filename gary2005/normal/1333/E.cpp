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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
int res[505][505];
int main(){
	fastio;
	cin>>n;
	if(n<=2){
		cout<<-1<<endl;
	}
	else
	{
		int cnt=1;
		int flag=0;
		rb(i,1,n-3){
			if(!flag){
				rb(j,1,n)
					res[i][j]=cnt++;
			} 
			else{
				rl(j,n,1)
					res[i][j]=cnt++;
			}
			flag^=1;	
		} 
		int num[3][3]={
		{1, 7, 9}
		 
,{3, 2, 5 },
{4, 8, 6} 
		 
		
		};
		if(!((n-3)&1)){
			//left 
			rb(j,1,n-3){
				rb(i,n-3+1,n){
					res[i][j]=cnt++;
				}
			}
			cnt--;
			rep(i,3)
				rep(j,3)
					res[n-3+1+i][n-3+1+j]=num[i][j]+cnt;
		}
		else{
			rl(j,n,4){
				rb(i,n-3+1,n)
					res[i][j]=cnt++;
			}
			
			cnt--;
			rep(i,3)
				rep(j,3)
					res[n-3+1+i][j+1]=num[2-i][2-j]+cnt; 
		}
		rb(i,1,n)
			rb(j,1,n)
			{
				cout<<res[i][j]<<" ";
				if(j==n) cout<<endl;
			}
	}
	return 0;
}