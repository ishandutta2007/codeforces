/*
	*#*#*#* Author GaryMr *#*#*#*
	
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
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int tot=0;
int num[45]={1};
int NUM;
int main(){
	int x;stack<int> v;
	scanf("%d",&x);
	NUM=x;
		int len=0;
		while(x){
			num[++len]=x&1;
			
			if(len!=1)if((num[len-1]==1&&num[len]==0)||(num[len-1]==0&&num[len]==1)){
//				cout<<len<<endl;
				v.push(len-1);
			}
			x>>=1;
		}//cout<<len<<endl;
		if(NUM%2==1)
		printf("%d\n",v.size()*2);
		else
		printf("%d\n",v.size()*2-1);
		int Size=v.size();
		for(int i=1;i<=Size;i++){//cout<<"E"<<endl;
			printf("%d ",v.top());
			v.pop();
		}
	return 0;
}