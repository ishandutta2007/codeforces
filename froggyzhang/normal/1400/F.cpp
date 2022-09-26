#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
#define N 1002
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,x,ans;
char s[N];
map<vector<int>,int> dp[N];
int main(){
	scanf("%s",s+1);
	x=read();
	n=strlen(s+1);
	dp[0][{}]=0;
	for(int i=1;i<=n;++i){
		dp[i]=dp[i-1];
		int mn=n;
		for(auto &x:dp[i])++x.second,mn=min(mn,x.second);
		int num=s[i]-'0';
		for(auto pre:dp[i-1]){
			if(x>15&&pre.second>mn+10)continue;
			vector<int> vec=pre.first;
			vec.push_back(num);
			int sum=0,pos=-1;
			bool ok=true;
			for(int j=(int)vec.size()-1;j>=0;--j){
				sum+=vec[j];
				if(sum==x&&!~pos){
					ok=false;
					break;
				}
				if(x%sum==0||sum>=x){
					pos=j;
					break;
				}
			}
			if(!ok)continue;
			vec.erase(vec.begin(),vec.begin()+pos+1);
			if(dp[i].count(vec))dp[i][vec]=min(dp[i][vec],pre.second);
			else dp[i][vec]=pre.second;
		}
	}	
	ans=n;
	for(auto x:dp[n]){
		ans=min(ans,x.second);
	}
	printf("%d\n",ans);	
	return 0;
}