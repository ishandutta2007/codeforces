/*
	Name: I will do my best in the next round #564 & #566
	Copyright: 
	Author: 
	Date: 04/06/19 21:02
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
const int MAXN=3e5+10; 
const LL MOD=1e9+7;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL n,m;
struct mat{
	LL body[105][105]; 
};
mat start_mat;
LL wide;
mat be;
mat ans;
mat chen(mat a,mat b){
	rb(k,1,wide){
	rb(i,1,wide){
//		rb(j,1,wide){
			ans.body[i][k]=0;
//			ans.body[i][k]%=MOD;
//		}
	}
	}
	rb(k,1,wide){
	rb(i,1,wide){
		rb(j,1,wide){
			ans.body[i][k]+=a.body[i][j]*b.body[j][k];
			ans.body[i][k]%=MOD;
		}
	}
	}
	return ans;
}
mat chen2(mat a,mat b){
//	mat ans;
	rb(k,1,1){
	rb(i,1,wide){
//		rb(j,1,wide){
			ans.body[i][k]=0;
//			ans.body[i][k]%=MOD;
//		}
	}
	}
	rb(k,1,1){
	rb(i,1,wide){
		rb(j,1,wide){
			ans.body[i][k]+=a.body[i][j]*b.body[j][k];
			ans.body[i][k]%=MOD;
		}
	}
	}
	return ans;
}
stack <int> order;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	if(m>n){
		cout<<1;
		return 0;
	}
	if(m==n){
		cout<<2;
		return 0;
	}
	rb(i,1,m){
		start_mat.body[i][1]=1;
	}
	
	start_mat.body[m+1][1]++;
	rb(i,1,m){
		rb(j,1,m+1){
			be.body[i][j]=0;
			if(j==i+1)
			be.body[i][j]++;
		}
	}
	rb(j,1,m+1){
		if(j==2||j==m+1){
			be.body[m+1][j]=1;
		}
		else{
			be.body[m+1][j]=0;
		}
	}
	LL num=n-m+1;
	while(num){
		order.push(num);
		num/=2;
	}
	wide=m+1;
	mat tmp=be;
	while(1){//cout<<1;
		int F=order.top();
//		cout<<F<<endl;
		order.pop();
		if(!order.size()) break;
		tmp=chen(tmp,tmp);
		if(F*2!=order.top()){
			tmp=chen(tmp,be);
		}
	}
	mat final=chen2(tmp,start_mat);
	cout<<final.body[m+1][1];
}