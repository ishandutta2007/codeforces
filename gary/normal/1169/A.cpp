/*
	*#*#*#* Author GaryMr *#*#*#*
########################################################################
	
	
	dfs or bfs
	
	c[i]
	
	long long
	
	dp
	
	:AABAB
	 >=0
	
	double> printf("%lf")6%.16lf
	
	dpg
	n8
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
	
	1<<int(ceil(log2(double(n))))
	or
	
	
	make_pair 
	
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL (long long)
#define IT iterator
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
//const int MAXN=  ;
//int n,a[MAXN];
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
//	scanf("%d",&n);
//	rb(i,1,n) scanf("%d",&a[i]);
	int n,a,x,b,y;
	cin>>n>>a>>x>>b>>y;
	while(1){
//		cout<<a<<" "<<b<<endl;
		if(a==b){
			cout<<"YES";
			return 0;
		}
		if(a==x||b==y) break;
		a++;
		b--;
		if(a==n+1) a=1;
		if(b==0) b=n;
//		cout<<a<<" "<<b<<endl;
	}
	cout<<"NO";
	return 0;
}