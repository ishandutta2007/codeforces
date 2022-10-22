/*
	*#*#*#* Author GaryMr *#*#*#*
########################################################################
	
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
	
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL long long
#define IT iterator
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL a[200000+10],b[200000+10];
int main(){
	LL n,m,ta,tb,k;
	cin>>n>>m>>ta>>tb>>k; 
	rb(i,1,n) scanf("%I64d",&a[i]);
	rb(i,1,m) scanf("%I64d",&b[i]);
	LL l=1;
	LL res=-1; 
	if(k>=n){
		cout<<-1;
		return 0;
	}
	rb(i,1,min(k+1,n)){
		LL tmpk=k-i+1;
		while(a[i]+ta>b[l]){
		 	l++;
		 	if(l>m) {
		 	cout<<-1;
		 	return 0;
		 	}
		}
		LL tmpl=l+tmpk;
		if(tmpl>m){
			cout<<-1;
			return 0;
		}
		res=max(res,b[tmpl]+tb);
	}
	printf("%I64d",res);
	return 0;
}