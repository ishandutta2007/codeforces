//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int las,now;
int k,p;
int safe[200000+10];
LL near[200000+10];
LL near2[200000+10];
vector<int> each[200000+10];
vector<pair<int,mp > > each2;
LL dp[200000+10][2];
int main(){
	memset(near,0x3f,sizeof(near));
	memset(near2,0x3f,sizeof(near2));
	memset(dp,0x3f,sizeof(dp));
//	cout<<dp[0][0]<<endl;
	int n,m;
	scanf("%d %d %d %d",&n,&m,&k,&p);
	rep(i,k){
		int xi,yi;
		scanf("%d %d",&xi,&yi);
		each[xi].PB(yi);
	}
	rb(i,1,n)
		sort(each[i].begin(),each[i].end());
	rep(i,p){
		int yi;
		scanf("%d",&yi);
		safe[yi]=1;
	}
	rb(i,1,m)
		near[i]=(safe[i])? (LL)(i):near[i-1];
	rl(i,m,1)
		near2[i]=(safe[i])? (LL)(i):near2[i+1];
	rb(i,1,n)
		if(!each[i].empty()){
//			cout<<i<<endl;
			each2.PB(II(i,II(each[i][0],each[i][each[i].size()-1])));
		}
	dp[0][1]=dp[0][0]=each2[0].FIR-1;
	LL l,r;
	l=each2[0].SEC.FIR;
	r=each2[0].SEC.SEC;
	if(each2[0].FIR==1) dp[0][0]=each2[0].SEC.SEC-1+each2[0].SEC.SEC-each2[0].SEC.FIR;
	else
	dp[0][0]+=abs(near2[1]-r)+near2[1]-1+r-l;
	if(each2[0].FIR==1) dp[0][1]=each2[0].SEC.FIR-1+each2[0].SEC.SEC-each2[0].SEC.FIR;
	else
	dp[0][1]+=abs(near2[1]-l)+near2[1]-1+r-l;
//	cout<<dp[0][1]<<" "<<dp[0][0]<<endl;
	LL lasl,lasr;
	lasl=l;
	lasr=r;
	rep(i,each2.size()){
		if(i){
			l=each2[i].SEC.FIR;
			r=each2[i].SEC.SEC;
			LL all_cost=r-l;
			if(near[lasl]!=near[0]){
				LL fircost=abs(lasl-near[lasl]);
				dp[i][0]=min(dp[i][0],dp[i-1][0]+abs(r-near[lasl])+all_cost+fircost);
				dp[i][1]=min(dp[i][1],dp[i-1][0]+abs(near[lasl]-l)+all_cost+fircost);                      
			}
			if(near2[lasl]!=near[0]){
				LL fircost=abs(lasl-near2[lasl]);
				dp[i][0]=min(dp[i][0],dp[i-1][0]+abs(r-near2[lasl])+all_cost+fircost);
				dp[i][1]=min(dp[i][1],dp[i-1][0]+abs(near2[lasl]-l)+all_cost+fircost); 
			}
			if(near[lasr]!=near[0]){
				LL fircost=abs(lasr-near[lasr]);
				dp[i][0]=min(dp[i][0],dp[i-1][1]+abs(r-near[lasr])+all_cost+fircost);
				dp[i][1]=min(dp[i][1],dp[i-1][1]+abs(near[lasr]-l)+all_cost+fircost); 
			}
			if(near2[lasr]!=near[0]){
				LL fircost=abs(lasr-near2[lasr]);
				dp[i][0]=min(dp[i][0],dp[i-1][1]+abs(r-near2[lasr])+all_cost+fircost);
				dp[i][1]=min(dp[i][1],dp[i-1][1]+abs(near2[lasr]-l)+all_cost+fircost); 
			}
			dp[i][0]+=each2[i].FIR-each2[i-1].FIR;
			dp[i][1]+=each2[i].FIR-each2[i-1].FIR;
			lasl=l;
			lasr=r;
//			cout<<each2[i].FIR<<endl;
		}
	}
//	cout<<dp[0][0]<<" "<<dp[0][1]<<endl;
	cout<<min(dp[each2.size()-1][0],dp[each2.size()-1][1])<<endl;
	return 0;
}