
/*######################################################################
	
	!
	
	dfs or bfs
	
	c[i]
	
	long long
	
	dp
	
	:AABAB
	 >=0
	
	double> printf("%lf")6%.16lf
	
	dpg
	n8
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
	
	1<<int(ceil(log2(double(n))))
	or
	
	
	make_pair 
	
	: dp[i]=dp[i-1]*2-dp[last[i]-1]
*/
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
int a[100001];
int dp[100001][11];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	rb(i,1,n){
		cin>>a[i];
	}
	rb(i,1,n){
		rb(j,1,10) dp[i][j]=dp[i-1][j];
		dp[i][a[i]]++;
	}
	rl(i,n,1){
		int ex1=0,ex2=0,num1=0,num2=0;
		bool OK=1,OK2=0;
		rb(j,1,10){
			if(dp[i][j]==0) continue;
			if(ex1==0||ex1==dp[i][j]) {
				ex1=dp[i][j];
				num1++;
			}
			else{
				if(ex2==0||ex2==dp[i][j]){
					 ex2=dp[i][j];
					 num2++;
				}
				else{
					OK2=true;
				}
			}	
		}
//		cout<<ex1<<" "<<ex2<<" "<<num1<<" "<<num2<<endl;
		if(OK2) continue;
		if(ex1==0){
			if(ex2==1){
				
				OK=0;
			}
			if(num2==1){
				OK=0;
			}
		}
		if(ex2==0){
			if(ex1==1){
				OK=0;
			}
			if(num1==1){
				OK=0;
			}
		}
		if(num1==1){
			if(ex1==ex2+1||ex1-1==0){
				OK=0;
			}
		}
		if(num2==1){
			if(ex2==ex1+1||ex2-1==0){
				OK=0;
			}
		}
		if(!OK){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}