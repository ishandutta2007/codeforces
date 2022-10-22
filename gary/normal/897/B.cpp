
/*######################################################################
	
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
	
	: dp[i]=dp[i-1]*2-dp[last[i]-1]
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL dp[100001]={0};
LL sum=0,num=0,wei=2,jiashu=11,maxnum=100;
int main(){
	ios::sync_with_stdio(false);
	LL k,p;
	cin>>k>>p;
	rb(i,1,k){
		if((num+1)==maxnum){
			wei+=2;
			maxnum*=100;
			jiashu*=10;
			num=0;
			num=maxnum/10;
			num++;
		}
		else{
			LL save_pow=10;
			bool flag=false;
			LL judge=maxnum/100,modnum=maxnum/10;
			LL tmpnum=num%modnum;
			LL jian=judge-1;
			tmpnum/=10;
			LL jia1=maxnum/10;
			jian*=10;
			LL jia2=1;
			rb(i,1,(wei-2)/2){
				if(flag) break;
				jian=(judge-1)*save_pow;
//				cout<<tmpnum<<" "<<judge-1<<endl;
				if(tmpnum==judge-1){				//cout<<judge<<" "<<tmpnum<<" "<<jian<<" "<<jia1+jia2<<endl;
					flag=1;
					num-=jian;
					num+=jia1;
					num+=jia2;
				}
				judge/=100;
				modnum/=100;
//				cout<<"<"<<modnum<<">"<<endl;
				tmpnum%=modnum;
				tmpnum/=10;
				
				jia1/=10;
				jia2*=10;
				save_pow*=10;
			}
			if(!flag){
				num+=jiashu;
			}
		}
//		cout<<"<<<"<<num<<endl;
		sum+=num;
	}
	printf("%I64d\n",sum%p);
	return 0;
}