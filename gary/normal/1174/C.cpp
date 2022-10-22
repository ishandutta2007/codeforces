/*
	Name: The last Virtual participation before the round #564
	Copyright: 
	Author: 
	Date: 06/06/19 17:35
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
int a[100004];
int res[100004];
int tmp=0;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
//	rb(i,1,n) cin>>a[i];
	rb(i,2,n){
		if(res[i]==0){
			tmp++;
			for(int j=i;j<=n;j+=i){
				res[j]=tmp;
			}
		}
	}
	rb(i,2,n){
	cout<<res[i]<<" ";
	}
	return 0;
}