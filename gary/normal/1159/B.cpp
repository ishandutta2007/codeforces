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
mp a[300003];
mp MAX_MIN[3000003];
int k=INF;
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i].FIR);
		a[i].SEC=i;
	}
	sort(a+1,a+1+n);
	
	MAX_MIN[n+1].FIR=INF;
	MAX_MIN[n+1].SEC=-INF;
	rl(i,n,1){
		MAX_MIN[i].FIR=min(MAX_MIN[i+1].FIR,a[i].SEC);
		MAX_MIN[i].SEC=max(MAX_MIN[i+1].SEC,a[i].SEC);
	}
	rb(i,1,n){
		int MAX_DIS;
//		cout<<i<<endl;
		MAX_DIS=max(abs(a[i].SEC-MAX_MIN[i].SEC),abs(a[i].SEC-MAX_MIN[i].FIR)) ;
		if(MAX_DIS==0) continue;
		k=min(k,a[i].FIR/MAX_DIS);
	}
	printf("%d\n",k);
	return 0;
}