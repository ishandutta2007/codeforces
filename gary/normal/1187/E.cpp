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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
struct node{
	vector<int> ch;
}a[200000+10];
int n;// the number of the nodes 
LL res[200000+10];
LL s[200000+10],dp[200000+10];
void Gary_dp(int now,int last){
	int SZ=a[now].ch.size();
	s[now]=1;
	dp[now]=0;
	rb(i,0,SZ-1){
		if(a[now].ch[i]==last) continue;
		Gary_dp(a[now].ch[i],now);
		s[now]+=s[a[now].ch[i]];
		dp[now]+=dp[a[now].ch[i]];
	}
	dp[now]+=s[now];
	return;
}
void change(int now,int last){
	res[now]=dp[now];
	int copy_data[4];
	int SZ=a[now].ch.size();
	rb(i,0,SZ-1){
		if(a[now].ch[i]==last) continue;
		copy_data[0]= dp[now]; 
		copy_data[1]= dp[a[now].ch[i]];
		copy_data[2]= s[now];
		copy_data[3]= s[a[now].ch[i]];
		
		dp[now]-=dp[a[now].ch[i]];
		dp[now]-=s[now];
		dp[a[now].ch[i]]-=s[a[now].ch[i]];
		s[now]-=s[a[now].ch[i]];
		s[a[now].ch[i]]=n;
		dp[now]+=s[now];
		dp[a[now].ch[i]]+=s[a[now].ch[i]];
		dp[a[now].ch[i]]+=dp[now];
		change(a[now].ch[i],now);
		
		dp[now]= copy_data[0]; 
		dp[a[now].ch[i]]= copy_data[1];
		s[now]= copy_data[2];
		s[a[now].ch[i]]= copy_data[3];
	}
	return;
}
int main(){
	scanf("%d",&n);
	rb(i,1,n-1){
		int ui,vi;
		scanf("%d %d",&ui,&vi);
		a[ui].ch.PB(vi);
		a[vi].ch.PB(ui);
	}
	Gary_dp(1,INF);
	res[1]=dp[1];
	change(1,INF);
	LL final=-INF;
	rb(i,1,n){
		final=max(res[i],final);
//		cout<<i<<" <-> "<<res[i]<<endl;
	}
	printf("%I64d\n",final);
	return 0;
}