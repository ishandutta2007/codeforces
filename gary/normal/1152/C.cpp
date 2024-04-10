/*
	*#*#*#* Author GaryMr *#*#*#*
	(a+k)(b+k)/gcd(a+k,b+k)  
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
#define LL long long
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL ans=900000000000000000,K;
LL gcd(LL a,LL b){
//	cout<<"DD"
	if(a<b) swap(a,b);
	if(min(a,b)==0){
		return max(a,b);
	}
	return gcd(b,a%b);
}
int main(){
	long long a,b;
	cin>>a>>b;
	LL cha=abs(a-b);
	for(int i=1;i*i<=cha;i++){
		if(cha%i==0){
			LL Y1=i,Y2=cha/Y1;
			LL k=Y1-(a%Y1);
			if(k==Y1) k=0;
			if(ans>(a+k)*(b+k)/gcd(a+k,b+k)){
				ans=(a+k)*(b+k)/gcd(a+k,b+k);
				K=k;
			}
			k=Y2-(a%Y2);
			if(k==Y2) k=0;
			if(ans>(a+k)*(b+k)/gcd(a+k,b+k)){
				ans=(a+k)*(b+k)/gcd(a+k,b+k);
				K=k;
			}
		}
	}
//	cout<<ans<<endl;
	printf("%I64d\n",K);
}