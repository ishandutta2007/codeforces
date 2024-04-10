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
//#define LL (long long)
#define IT iterator
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,a[300001]={-INF};
bool check(int x){
//	int fir=min((a[1]+x)%m,a[1]);
	int next=-INF;
	rb(i,1,n){
//		cout<<next<<endl;
		int flag=0;
		int LL1,LL2,RR1,RR2;
		if((a[i]+x)>=m){
			flag=1;
			LL1=0,RR1=(a[i]+x)%m;
		}
		if(flag){
			LL2=a[i],RR2=m-1;
		}
		else{
			LL1=a[i],RR1=a[i]+x;
		}
		int tmpOK=0;
		if(flag){
			int tmp=INF;
			if(next<=RR1){
				tmpOK=1;
				tmp=min(tmp,LL1);
			}
			if(next<=RR2){
				tmpOK=1;
				tmp=min(tmp,LL2);
			}
			if(!tmpOK){
				return false;
			}
			next=max(next,tmp);
		}
		else{
			if(next<=RR1){
				tmpOK=1;
				next=max(next,LL1);
			}
			else{
				return false;
			}
		}
	}
	return true;
}
int main(){
	scanf("%d %d",&n,&m);
	rb(i,1,n){
		scanf("%d",&a[i]);
	}
	int l=0,r=m;
//	cout<<check(0);cout<<"-------------------"<<endl; 
	while(l<r){
		int mid=(l+r)>>1;
//		cout<<l<<" "<<r<<" "<<mid<<endl;
		if(check(mid)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	
//	cout<<"-----------------"<<endl;cout<<check(463)<<endl; 
	printf("%d\n",l);
	return 0;
}