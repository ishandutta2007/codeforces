/*
	MAIN IDEA:
	AC PLEASE
	I know this will be TLE , however no matter,because I know how to do better (^-^)
	dp[i][j]=0 ( if j-Ti<0 )
	dp[i][j]=dp[i-1][j-Ti]*(1-p[i])^((Ti)-1)  ( else )
	dp[i][j]=SIC(k:1 to Ti-1)) dp[i-1][j-k]*(1-Pi)k-1*Pi( if j-k>=0 )
	Name: 
	Copyright: 
	Author: 
	Date: 05/06/19 21:10
	Description: 
*/

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
#define R(a) cin>>a;
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=5e3+10;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,T;
double p[MAXN];int t[MAXN];
double ans=0;
double dp[MAXN][MAXN];
inline double super_pow(double num,int now){
	if(num==0) return 0;
//	if(num==1) return 1;
	if(now==0) return 1;
	if(now==1) return num;
	if(now&1){
		return super_pow(num,now/2)*super_pow(num,now/2)*num;
	}
	else return super_pow(num,now/2)*super_pow(num,now/2);
}
void work(){
	rb(i,1,n){
		double NOW=0;
		double R=super_pow(1-p[i],t[i]-1);
		rb(j,1,T){
			
			if(j-t[i]<0) dp[i][j]=0;
			else dp[i][j]=dp[i-1][j-t[i]]*R;
			double SQUARE=1.0;
			if(j>t[i]-1) {
				double minus_num=dp[i-1][j-t[i]]*R*p[i];
				if((1.0-p[i])) minus_num/=(1.0-p[i]);
				NOW-=minus_num;
			}
			NOW*=(1.0-p[i]);
			NOW+=dp[i-1][j-1]*p[i];
			dp[i][j]+=NOW;
			ans+=dp[i][j];
		}
	}
}
int main(){
	memset(dp,0,sizeof(dp));
	ios::sync_with_stdio(false);
	R(n);
	R(T);
	rb(i,1,n){
		cin>>p[i]>>t[i];
		p[i]/=100.0;
	}
	dp[0][0]=1;
	work();
	printf("%.12f",ans);
	return 0;
}