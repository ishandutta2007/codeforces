/*
	*#*#*#* Author GaryMr *#*#*#*
########################################################################
	
	!
	
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
#define LL long long
#define IT iterator
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a[300001];int n;
map<int,int> MM;
map<int,int> MM2;
vector<mp> res;
void my_swap(int lo1,int lo2){
	if(lo1>lo2) swap(lo1,lo2);
	int tmp1=MM2[lo1],tmp2=MM2[lo2];
	if(lo2-lo1>=n/2){
		res.push_back({lo1,lo2});
		MM[tmp1]=lo2;
		MM[tmp2]=lo1;
		swap(MM2[lo1],MM2[lo2]);
	}
	else{
		int lo3;
		if(lo2+n/2<=n) {
			lo3=n;
			
		}
		else 
			lo3=1;
		
		if(abs(lo3-lo1)>=n/2){
			my_swap(lo2,lo3);
			my_swap(lo3,lo1);
			my_swap(lo2,lo3);
		}
		else{
			int lo4;
			if(lo3==1) lo4=n;
			else lo4=1;
			my_swap(lo2,lo3);
			my_swap(lo3,lo4);
			my_swap(lo1,lo4);
			my_swap(lo3,lo4);
			my_swap(lo2,lo3);
		}
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]),MM[a[i]]=i,MM2[i]=a[i];
	rb(i,1,n){
		int now=MM[i];
		if(i!=now) my_swap(i,now);
		
	}
	if(res.size()==0) cout<<0;
	else{
		cout<<res.size()<<endl;
		rb(i,0,res.size()-1){
			printf("%d %d\n",res[i].FIR,res[i].SEC);
		}
	}
	return 0;
}