
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
int main(){
	ios::sync_with_stdio(false);
	//GOOD LUCK
	int n;
	cin>>n;
	queue<mp> res;
	int bian=-INF;
	int lastx=0,lasty=1; 
	rb(i,1,n){
		int nowx,nowy;
		if(i&1){
			nowx=lastx+1;
			nowy=lasty;
		}
		else{
			nowx=lastx;
			nowy=lasty+1;
		}
		res.push(II(nowx,nowy));
		bian=max(bian,max(nowx,nowy));
		swap(nowx,lastx);
		swap(lasty,nowy);
	}
	cout<<bian<<endl;
	rb(i,1,n){
		cout<<res.front().FIR<<" "<<res.front().SEC<<endl;
		if(i!=n) res.pop();
	}
	return 0;
}