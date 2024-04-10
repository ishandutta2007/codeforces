#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
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
int n,m;
char ma[1001][1001];
int dp[1001][1001];
mp have[1001][1001];
int main(){
	ios::sync_with_stdio(false);
//	freopen("random.in", "r", stdin);
//    freopen("bf.out", "w", stdout);  
	 cin>>n>>m;
	 rb(i,1,n){
	 	rb(j,1,m){
	 		cin>>ma[i][j];
	 	}
	 }
	rb(i,1,n){
		rb(j,1,m){
			dp[i][j]=1;
			if(ma[i][j]==ma[i-1][j]){
				dp[i][j]+=dp[i-1][j];
			}
			//cout<<dp[i][j]<<" "; 
		}//cout<<endl;
	}
	rb(i,1,n){
		rb(j,1,m){
			have[i][j].FIR=have[i][j].SEC=0;
			have[i][j].SEC=dp[i][j];
			rl(k,j,1){
				if(ma[i][k]!=ma[i][j]||dp[i][k]<dp[i][j]) break;
				have[i][j].FIR++;
			}
//			cout<<"<"<<have[i][j].FIR<<":"<<have[i][j].SEC<<" "<<i<<" "<<j<<">"; 
		}//cout<<endl;
	}
	LL res=0;
	rb(i,1,n){
		rb(j,1,m){
			int KUAN=have[i][j].FIR;
			int GAO=have[i][j].SEC;
			if(i-GAO*2<=0) continue;			
			int tmpKUAN=0;
			if(have[i-GAO][j].SEC!=GAO){
				continue;
			}
			KUAN=min(KUAN,have[i-GAO][j].FIR);
			rb(k,1,KUAN){
				if(ma[i-GAO*2][j-k+1]!=ma[i-GAO*2][j]||dp[i-GAO*2][j-k+1]<GAO){
					break;
				}
				tmpKUAN++;
			}
			KUAN=min(KUAN,tmpKUAN);
//			KUAN=min(have[i-GAO][j].FIR,min(KUAN,have[i-GAO*2][j].FIR));
			res+=KUAN;
//			cout<<res<<" "<<i<<","<<j<<endl;
		}
	}
	cout<<res<<endl;
	return 0;
}