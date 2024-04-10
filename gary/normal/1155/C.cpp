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
#define ll long long;
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m;//<=300000
long long x[300001],p[300001],cha,mini=1000000000000000001;
long long gcd(long long a,long long b){
	if(min(a,b)==0){
		return max(a,b);
	}
	return gcd(b,a%b);
}
int main(){
	scanf("%d %d",&n,&m);
	rb(i,1,n) {
	scanf("%I64d",&x[i]);
	mini=min(mini,x[i]);
	}
	rb(i,1,m) scanf("%I64d",&p[i]);
	rb(i,2,n){
	 	cha=gcd(x[i]-x[i-1],cha);
	}
	rb(i,1,m){
		if(cha%p[i]==0){
			printf("YES\n%I64d %d",mini,i);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}