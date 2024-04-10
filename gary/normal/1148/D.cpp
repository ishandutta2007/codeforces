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
bool cmp(pair<mp,int> A,pair<mp,int> B){
	return A.FIR.FIR>B.FIR.FIR;
}
int main(){
	vector<pair<mp,int> > type1;
	vector<pair<mp,int> > type2;
	int n;
	scanf("%d",&n);
	rb(i,1,n) {
		int a,b;
		scanf("%d %d",&a,&b);
		if(a<b){
			type1.push_back(II(II(b,a),i));
		}
		else{
			type2.push_back(II(II(b,a),i));
		}
	}
	int res1=0,res2=0;
	sort(type1.begin(),type1.end(),cmp);
	sort(type2.begin(),type2.end());
	res1=type1.size();
       res2=type2.size();
	if(res1>res2){
		printf("%d\n",res1);
		rb(i,1,res1){
			printf("%d ",type1[i-1].SEC);
		}
	}
	else{
		printf("%d\n",res2);
		rb(i,1,res2){
			printf("%d ",type2[i-1].SEC);
		}
	}
	return 0;
}