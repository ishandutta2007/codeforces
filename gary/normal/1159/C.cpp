/*
	*#*#*#* Author GaryMr *#*#*#*
########################################################################
	
	
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
LL n,m;
LL b[100001],g[100001];
LL sumb,sumg,minG=INF;
LL ming=INF,maxb=-INF;
int main(){
	scanf("%I64d %I64d",&n,&m);
	rb(i,1,n) scanf("%I64d",&b[i]),maxb=max(maxb,b[i]),sumb+=b[i];
	rb(i,1,m) scanf("%I64d",&g[i]),ming=min(ming,g[i]),sumg+=g[i],minG=min(minG,g[i]);
	LL next_big=-INF;
	LL OK=1;
	rb(i,1,n){
		if(OK){
			if(b[i]==maxb){
				OK=0;
				continue;
			}
		}
		next_big=max(next_big,b[i]);
	}
	if(maxb>ming){
		printf("-1");
		return 0;
	}
	LL res=sumb*m;
	sumg-=minG;
//	cout<<res<<endl;
	res+=sumg-(maxb*(m-1));
//	cout<<sumg<<" "<<maxb*(m-1);
//	cout<<res<<endl;
	if(minG==maxb)
	res+=minG-maxb;
	else
	res+=minG-next_big;
	printf("%I64d\n",res);
	return 0;
}