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
	int tot2=0;
	cin>>n;
	rb(i,1,n){
		int a;
		cin>>a;
		if(a==2){
			tot2++;
		}
	}
	if(tot2!=0){
		cout<<2<<" " ;
	}
	if(n-tot2!=0){
		cout<<1<<" ";
	}
	rb(i,2,tot2){
		cout<<2<<" ";
	}
	rb(i,1,n-tot2-1){
		cout<<1<<" ";
	}
	return 0;
}