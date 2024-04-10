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
map<char,int> MM;
int main(){
	int  n;
	scanf("%d",&n);
	rb(i,1,n){
		string s;
		cin>>s;
		MM[s[0]]++;
	}
	map<char,int> ::IT ite=MM.begin();
	int res=0;
	for(ite;ite!=MM.end();ite++){
		double fir=ite->SEC/2,sec=ite->SEC-fir;
//		cout<<fir<<" "<<sec<<" "<<int((fir+1)*fir/2.0)<<" "<<int((sec+1)*sec/2.0)<<endl;
		res+=max(int((fir)*(fir-1)/2.0),0)+max(int((sec)*(sec-1)/2.0),0);
	}
	printf("%d\n",res);
	return 0;
}