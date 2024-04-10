/*
	*#*#*#* Author GaryMr *#*#*#*
	
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
	int n;
char c;
cin>>n;
char minc='*';
int weizhi1,weizhi2;
	rb(i,1,n){
		cin>>c;
		if(minc=='*'||c>minc){
			weizhi1=i;
			minc=c;
		}
		if(c<minc){
			weizhi2=i;
			cout<<"YES"<<endl;
			cout<<weizhi1<<" "<<weizhi2;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}