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
	int T;
	scanf("%d",&T);
	rb(k,1,T){
		int len;
		string s;
		cin>>len>>s;
		int first=len-1,last=0;
		rb(i,0,len-1){
			if(s[i]=='>'){
				first=i;
				break;
			}
		}
		rl(i,len-1,0){
			if(s[i]=='<'){
				last=i;
				break;
			}
		}
		cout<<min(first-0,(len-1)-last)<<endl;
	}
	return 0;
}