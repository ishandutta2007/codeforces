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
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
char tab[5]={'a','e','i','o','u'};
int main(){
	bool OK;
	OK=0;
	int n,m;
	int k;
	scanf("%d",&k);
	for(int i=5;i<=k;i++){
		if(k%i!=0) continue;
		if(i>=5&&(k/i)>=5){
			OK=1;
			n=i;
			m=(k/i);
		}
	}
	if(!OK){
		printf("%d\n",-1);return 0;
	}
	rb(i,1,n){
		rb(j,1,m){
			printf("%c",tab[(i+j)%5]);
		}
//		cout<<endl;
	}
	return 0;
}