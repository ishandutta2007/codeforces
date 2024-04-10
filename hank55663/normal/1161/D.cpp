#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
char c[1005];
int mod=998244353;
int vis[2][1005];
LL ans[2];
int flag=0;
LL go(int op,int x,int len1,int len2){
	if(op==1&&x>=len2)return ans[0];
	if(op==0){
		int ori=x;
		vis[op][x]=1;
		x = len1-x-1;
		vis[op][x]=1;
		if(x==ori)return (ans[0]+ans[1])%mod;
		if(c[x]=='1'){
			swap(ans[0],ans[1]);
		}
		else if(c[x]=='?'){
			ans[0]+=ans[1];
			ans[0]%=mod;
			ans[1]=ans[0];
		}
		return go(1,x,len1,len2);
	}
	if(op==1){
		int ori=x;
		if(x==len2-1)
		ans[0]=0;
		vis[op][x]=1;
		x = len2-x-1;
		vis[op][x]=1;
		if(x==len2-1)
		ans[0]=0;
		if(x==ori)return (ans[0]+ans[1])%mod;
		if(c[x]=='1'){
			swap(ans[0],ans[1]);
		}
		else if(c[x]=='?'){
			ans[0]+=ans[1];
			ans[0]%=mod;
			ans[1]=ans[0];
		}
		return go(0,x,len1,len2);
	}
}
int main(){
	scanf("%s",c);
	int len=strlen(c);
//	printf("%d\n",len);
	reverse(c,c+len);
//	printf("%s\n",c);
	LL aans=0;
	for(int i = 1;i<len;i++){
		LL sum=1;
		MEM(vis);
		for(int j = len-1;j>=0;j--){
			if(!vis[0][j]){
				if(c[j]=='0')
				ans[0]=1,ans[1]=0;
				else if(c[j]=='1')
				ans[1]=1,ans[0]=0;
				else
				ans[0]=ans[1]=1;
				if(i==2&& j ==len-1){
					flag = 1;
				}
				LL x = go(0,j,len,i);
				flag=0;
				sum*=x;
				sum%=mod;
			}
		}
		aans+=sum;
	//	printf("%d %lld %lld\n",i,sum,aans);
	}
	printf("%lld\n",aans%mod);
}
/*

2*5!     240
2*4!*5   240
2*3!*10 120
2*2!*10 40
2*1!*5  10
2    2

*/