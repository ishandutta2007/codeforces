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
LL k;
void solve(){
	
	LL now=9;
	LL last=1;
//	cin>>k;
	if(k<=9) {
		cout<<k<<endl;
		return ;
	}
//	k-=now;
	LL finalk=k;
	LL pow=1;
	rb(step,1,15){
		LL tmplast=last-1;	
		if(k<=now){
			LL this_num=tmplast+(k/step);
			bool OK=1;
			LL tmpnum=this_num;
			rb(i,1,step){
				if(tmpnum%10!=9) OK=false;
				tmpnum/=10;
			}
			if(OK) step++;
			if(k%step) this_num+=1;
			LL yiwei=(step-k%step);
			if(yiwei==step) yiwei=0;
			rb(i,1,yiwei){
				this_num/=10;
			}
			printf("%d\n",this_num%10);
			return ;
		}	
		k-=now;	
		pow*=10;
		now=9*pow;
		now*=(step+1);
		last*=10;
	}
}
LL Cen[5000000];
int main(){
	int q;
	cin>>q;
	Cen[1]=1;
	rb(i,2,5000000-1){
		int wei=0;
		int tmp=i;
		while(tmp){
			wei++;
			tmp/=10;
		}
		Cen[i]=Cen[i-1]+wei;
	}
	while(q--){
		
		cin>>k;
		
	int tmp=1;
	while(1){
		if(k<=Cen[tmp]) break;
		k-=Cen[tmp];
		tmp++;
	}
//	cout<<k<<endl;
	solve();
	}
	
	return 0;
}