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
int num[50];
bool cmp(int A,int B){
	return A>B;
}
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n){
		char c;
		cin>>c;
		num[i]=c^48;
	}
	rb(i,1,n){
		if(num[i]==6){
			num[i]=5;
			num[++n]=3;
		}
		if(num[i]==4){
			num[i]=3;
			num[++n]=2;
			num[++n]=2;
		}
		if(num[i]==8){
			num[i]=7;
			num[++n]=2;
			num[++n]=2;
			num[++n]=2;
//			num[++n]=2;
		}
		if(num[i]==9){
			num[i]=2;
			num[++n]=3;
			num[++n]=3;
			num[++n]=7;
//			num[++n]=2;
//			num[++n]=2;
		}
	}
	sort(num+1,num+1+n,cmp);
	rb(i,1,n){
		if(num[i]==1||num[i]==0) break;
	cout<<num[i];
		}
	return 0;
}