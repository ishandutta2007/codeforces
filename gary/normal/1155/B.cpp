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
int everperson;
int main(){
	int n,tot=0,toteight=0;char c;int a;
	scanf("%d",&n);
	everperson=(n-11)/2;
	tot=everperson;
	rb(i,1,n){
		cin>>c;
		a=c^48;
//		cout<<a<<endl;
		if(tot<0) break;
		if(a!=8) tot--;
		if(a==8){
			toteight++;
		}
	}
//	cout<<toteight<<" ";
	if(toteight>everperson) printf("YES\n");
	else printf("NO\n");
	return 0;
}