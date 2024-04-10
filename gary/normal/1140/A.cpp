/*
	*#*#*#* Author GaryMr *#*#*#*
########################################################################
	
	
	c[i]
	
	long long
	
	dp
	
	 >=0
	
	dpg
	n8
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
	
	1<<ceil(log2(double(n)))
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define IT iterator
#define FIR first
#define SEC second
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	int n;
	scanf("%d ",&n);
	int last=0;
	int ans=0;
	rb(i,1,n){
		if(i>last) ans++;
		int ai;
		scanf("%d",&ai);
		last=max(last,ai);
	}
	printf("%d\n",ans);
	return 0;
}