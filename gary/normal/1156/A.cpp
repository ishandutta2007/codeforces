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
const int MAXN=101;
int n,a[MAXN];
int main(){
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i]);
		
	}
	int ans=0;
	rb(i,2,n){
		if(a[i]==1){
			if(a[i-1]==2){
				ans+=3;
				
			}
			if(a[i-1]==3)
			{
				ans+=4;
				
			}
//			if(a[i-1]==1){
//				cout<<"Infinite"<<endl;
//				return 0;
//			} 
		}
		if(a[i]==2){
//			if(a[i-1]==2){
//				ans+=3;
//				
//			}
			if(a[i-1]==3)
			{
				cout<<"Infinite"<<endl;
				return 0;	
			}
			if(a[i-1]==1){
				ans+=3;
			} 
		}
		if(a[i]==3){
			if(a[i-1]==2){
				cout<<"Infinite"<<endl;
				return 0;
				
			}
//			if(a[i-1]==3)
//			{
//				ans+=4;
//				
//			}
			if(a[i-1]==1){
				ans+=4;
			} 
		}
		if(i>=3){
			if(a[i]==2&&a[i-1]==1&&a[i-2]==3){
				ans--;
			}
		} 
	} 
	cout<<"Finite"<<endl;
	cout<<ans<<endl;
	return 0;
}