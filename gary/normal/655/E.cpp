/*
	Name: Intellectual Inquiry
	Copyright: GaryMr
	Author: GaryMr
	Date: 02/06/19 10:10
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
#define II(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=1000000;
const int MOD=1e9+7;
typedef pair<LL,LL> mp;
typedef pair<mp,mp> superpair;
LL len;
string s;
LL n,k;
map<LL,LL> last;
vector<mp> sorted_vector;
LL dp[2*MAXN+10]={1};
int main(){
	cin>>n>>k;
	string tmp;
	cin>>tmp;
	s+=" ";
	s+=tmp;
	int len=s.length();
	rb(i,1,len-1){
		if(last[s[i]-'a'+1])
		dp[i]=dp[i-1]*2-dp[last[s[i]-'a'+1]-1];
		else
		dp[i]=dp[i-1]*2;
		while(dp[i]<0) dp[i]+=MOD;
		dp[i]%=MOD;
		last[s[i]-'a'+1]=i;//renew the last
//		cout<<dp[i]<<endl;
//		cout<<s[i]<<" ";
	} 
	
	rb(i,0,k-1){
//		cout<<i<<" ";
		sorted_vector.PB(II(last[i+1],i+1));
	}
	sort(sorted_vector.begin(),sorted_vector.end());
	rb(i,0,n-1){
		mp now=*sorted_vector.begin();
		sorted_vector.erase(sorted_vector.begin());
		dp[i+len]=dp[(i+len-1)]*2-dp[last[now.SEC]-1];
		while(dp[i+len]<0) dp[i+len]+=MOD; 
		dp[i+len]%=MOD;//cout<<last[now.SEC]<<endl;
		last[now.SEC]=i+len;
		sorted_vector.PB(II(INF,now.SEC));
		
	}
	printf("%I64d\n",dp[len+n-1]);
	return 0;
}