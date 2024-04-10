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
char cc4[50]={'T','"','?'};
char cc3[100]={'^','"','?',' ','A','r','e',' ','y','o','u',' ','b','u','s','y','?',' ','W','i','l','l',' ','y','o','u',' ','s','e','n','d',' ','"'};
char cc2[100]={'$','W','h','a','t',' ','a','r','e',' ','y','o','u',' ','d','o','i','n','g',' ','a','t',' ','t','h','e',' ','e','n','d',' ','o','f',' ','t','h','e',' ','w','o','r','l','d','?',' ','A','r','e',' ','y','o','u',' ','b','u','s','y','?',' ','W','i','l','l',' ','y','o','u',' ','s','a','v','e',' ','u','s','?'};
char cc[37]={'&','W','h','a','t',' ','a','r','e',' ','y','o','u',' ','d','o','i','n','g',' ','w','h','i','l','e',' ','s','e','n','d','i','n','g',' ','"'};
char work(LL N,LL K){
	if(N==0){
		return cc2[K];
	}
	if(K<=34){
		return cc[K];//34
	}
	K-=34;
	if(N>55){
		N--;
		return work(N,K);
	}
	if(K<=dp[N-1]){
		return work(N-1,K);//75
	}
	K-=dp[N-1];
	if(K<=32){
		return cc3[K];//32
	}
	K-=32;
	if(K<=dp[N-1]){
		return work(N-1,K);//75
	}
	K-=dp[N-1];
	return cc4[K];//2
}
int main(){	
	ios::sync_with_stdio(false);
	int q;
	cin>>q;
	dp[0]=75;
	rb(i,1,55){
			dp[i]=dp[i-1]*2+68;
//			cout<<dp[i]<<" "<<i<<endl;
	}
	rb(i,1,q){
		LL n,k;
		cin>>n>>k;
		if(k>dp[n]){
			if(n<=55)
			cout<<".";
			else{
				cout<<work(n,k);
			}
		}
		else{
			cout<<work(n,k);
		}
	}
	return 0;
}