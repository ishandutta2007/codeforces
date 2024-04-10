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
	long long n;long long k;
cin>>n>>k;
if(k==1){
	cout<<"YES"<<endl;
	cout<<n;
	return 0;
}
	long long leastcost=((1+k)*k/2);
	if(n<leastcost) {
//		cout<<"F"<<endl;
		printf("NO\n");
		return 0;
	}
	long long eachadd=(n-leastcost)/k;
	n-=leastcost;
	n%=(k);
	long long ans[100001];
	rb(i,1,k){
		ans[i]=i+eachadd;
}
	rl(i,k,2){
		int lastai=ans[i];
		ans[i]=min(ans[i-1]*2,ans[i]+n);
		n-=ans[i]-lastai;
		if(n<=0){
			printf("YES\n");
			rb(i,1,k){
				printf("%I64d ",ans[i]);
			}
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}