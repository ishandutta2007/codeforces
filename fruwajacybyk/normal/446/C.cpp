#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int
#define max_n 1000005

using namespace std;

int val[2*max_n];
PII lazy[2*max_n];

int mod = 1e9+9;

int fib[max_n];
int fsum[max_n];
int start[max_n];

int n;

void build(int node,int a,int b){
	if(a>b) return;
	if(a==b){
		val[node] = start[a]%mod;
		return;
	}
	build(2*node,a,(a+b)/2);
	build(2*node+1,(a+b)/2+1,b);
	val[node] = (val[2*node]+val[2*node+1])%mod;
}

void add(int node,int a,int b,int i,int j){
	if(lazy[node]!=mp(0,0)){
			int u = lazy[node].st, v = lazy[node].nd;
			if(a!=b){
				val[node] += (u*1LL*(fsum[b-a-1]+1))%mod;
				val[node]%=mod;

				val[node] += (v*1LL*fsum[b-a])%mod;
				val[node]%=mod;

				lazy[2*node].st+=u;
				lazy[2*node].nd+=v;
				int st1 = (u*1LL*(fib[(b-a)/2]) + v*1LL*(fib[(b-a)/2+1] ))%mod;
				int nd1 = (u*1LL*(fib[(b-a)/2+1]) + v*1LL*(fib[(b-a)/2+2] ))%mod;
				
				lazy[2*node+1].st+=st1;
				lazy[2*node+1].nd+=nd1;

				lazy[2*node].st%=mod;
				lazy[2*node].nd%=mod;
				lazy[2*node+1].st%=mod;
				lazy[2*node+1].nd%=mod;


			}
			else{
				val[node] = (val[node]+ u )%mod;
			}
			val[node]%=mod;
		
		lazy[node] = mp(0,0);
	}	

	if(a > b || a > j || b < i) return; 

	if(a>=i && b<=j){
		val[node] += (fsum[b-i+1]+mod-fsum[a-i])%mod;
		val[node]%=mod;

		if(a!=b){
			lazy[2*node].st+=fib[a-i+1];
			lazy[2*node].nd+=fib[a-i+2];
			lazy[2*node+1].st+=fib[(a+b)/2+1-i+1];
			lazy[2*node+1].nd+=fib[(a+b)/2+1-i+2];

			lazy[2*node].st%=mod;
			lazy[2*node].nd%=mod;
			lazy[2*node+1].st%=mod;
			lazy[2*node+1].nd%=mod;
		}

		return ;
	}

	add(2*node,a,(a+b)/2,i,j);
	add(2*node+1,(a+b)/2+1,b,i,j);

	val[node] = (val[2*node]+val[2*node+1])%mod;
}

int query(int node,int a,int b, int i,int j){
	if(lazy[node]!=mp(0,0)){
			int u = lazy[node].st, v = lazy[node].nd;
			if(a!=b){
				val[node] += (u*1LL*(fsum[b-a-1]+1))%mod;
				val[node]%=mod;

				val[node] += (v*1LL*fsum[b-a])%mod;
				val[node]%=mod;

				lazy[2*node].st+=u;
				lazy[2*node].nd+=v;
				int st1 = (u*1LL*(fib[(b-a)/2]) + v*1LL*(fib[(b-a)/2+1] ))%mod;
				int nd1 = (u*1LL*(fib[(b-a)/2+1]) + v*1LL*(fib[(b-a)/2+2] ))%mod;
				
				lazy[2*node+1].st+=st1;
				lazy[2*node+1].nd+=nd1;

				lazy[2*node].st%=mod;
				lazy[2*node].nd%=mod;
				lazy[2*node+1].st%=mod;
				lazy[2*node+1].nd%=mod;


			}
			else{
				val[node] = (val[node]+ u )%mod;
			}
			val[node]%=mod;
		
		lazy[node] = mp(0,0);
	}	



	
	if(a>b || a>j || b < i) return 0;


	if(a>=i && b<=j) return val[node]%mod;

	int q1 = query(2*node,a,(a+b)/2,i,j);
	int q2 = query(2*node+1,(a+b)/2+1,b,i,j);

	return (q1+q2)%mod;
}


int main(){
	fib[0]=0; fib[1]=1;
	FOR(i,2,max_n) fib[i]=(fib[i-1]+fib[i-2])%mod;
	FOR(i,1,max_n) fsum[i] = (fib[i]+fsum[i-1])%mod;

	int q; scanf("%d%d",&n,&q);

	FOR(i,0,n){
		int u;
		scanf("%d",&u);
		start[i] = u;
	}

	build(1,0,n-1);



	FOR(i,0,q){
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		if(x==1){
			add(1,0,n-1,y-1,z-1);
		}
		else printf("%d\n",query(1,0,n-1,y-1,z-1)%mod);
		
	}



	return 0;
}