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
	
	
	make_pair 
	
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL (long long)
#define IT iterator
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
pair<int,int> p[300001];
int num1=INF,num2=INF;
int n,m;
bool dfs(int now){
	if(now==m+1) return 1;
	if(p[now].FIR==num1||p[now].FIR==num2||p[now].SEC==num1||p[now].SEC==num2) return dfs(now+1);
	if(num2==INF){
		num2=p[now].SEC;
		int OK=0;
		OK=dfs(now+1);
		num2=p[now].FIR;
		if(!OK) OK=dfs(now+1);
		if(OK) return true;
		else return false;
	}
	else{
		return false;
	}
} 
int main(){
	scanf("%d %d",&n,&m);
	rb(i,1,m){
		scanf("%d %d",&p[i].FIR,&p[i].SEC);
	}
	num1=p[1].FIR;
	if(dfs(1)){
		printf("YES");
		return 0;
	}
	num1=p[1].SEC;
	num2=INF;
	if(dfs(1)){
		printf("YES");
		return 0;
	}
	printf("NO");
	return 0;
}