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
map<int,int> uni;
LL ans=0;
int rest=0;
vector<int> each_node[200000+10];
int dfs(int now,int last){
	int tmp=0;
	tmp+=uni[now];
	rb(i,0,each_node[now].size()-1){
		if(each_node[now][i]==last) continue;
		tmp+=dfs(each_node[now][i],now);
	}
	while(tmp*2>rest) tmp-=2,rest-=2;
	ans+=tmp;
	return tmp;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	k*=2;
	rest=k;
	rb(i,1,k){
		int numa;
		scanf("%d",&numa);
		uni[numa]=true;
	}//cout<<"OK"<<endl;
	rb(i,1,n-1){
		int AA,BB;
		scanf("%d %d",&AA,&BB);
		each_node[AA].push_back(BB);
		each_node[BB].push_back(AA);
	}
	dfs(1,INF);
	printf("%I64d\n",ans);
	return 0;
}