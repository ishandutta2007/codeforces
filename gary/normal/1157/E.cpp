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
//	freopen("out.out","r",stdin);
//	freopen("out.in","w",stdout);
	vector<int> a;
	vector<int> b;
/*TEST
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);
	b.erase(find(b.begin(),b.end(),4));
	vector<int> ::IT ite;
	for(ite=b.begin();ite!=b.end();ite++){
		cout<<*ite<<" ";
	}
test*/
	int n,ai;
	scanf("%d",&n);
	rb(i,0,n-1){
		scanf("%d",&ai);
		a.push_back(ai);
	}
	rb(i,0,n-1){
		scanf("%d",&ai);
		b.push_back(ai);
	}
	sort(b.begin(),b.end());
//	cout<<b[0];
	int now=0;
	rb(i,0,n-1){
		int minimum;vector<int>::IT maximum;
		minimum=b[now];
		maximum=lower_bound(b.begin()+now,b.end(),n-a[i]);
		if(maximum==b.end()||*maximum==b[0]){
			printf("%d ",(minimum+a[i])%n);
//			b.erase(b.begin());
			now++;
			continue;
		} 
		if((minimum+a[i])%n<(*maximum+a[i])%n){
			printf("%d ",(minimum+a[i])%n);
			now++;
//			b.erase(b.begin());
		}
		else{
			printf("%d ",(*maximum+a[i])%n);
			b.erase(maximum);
		} 
	}
	return 0;
}