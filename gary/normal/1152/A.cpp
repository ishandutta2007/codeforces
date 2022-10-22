/*
	*#*#*#* Author GaryMr *#*#*#*
	
	c[i]
	
	long long
	
	dp
	
	 >=0
	
	dpg
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
	
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
	int n,m;
	int t1j=0,t1o=0,t2j=0,t2o=0;
	scanf("%d %d",&n,&m);
	rb(i,1,n){
		int num;
		scanf("%d",&num);
		if(num%2){
			t1j++;
		}
		else{
			t1o++;
		}
	}
	rb(i,1,m){
		int num;
		scanf("%d",&num);
		if(num%2){
			t2j++;
		}
		else{
			t2o++;
		}
	}
	int ans=min(t2j,t1o)+min(t1j,t2o);
	printf("%d\n",ans);
	return 0;
}