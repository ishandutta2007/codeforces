#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define gc getchar()
#define N 200010
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
int n,k,ans,p[26];char s[60];
int main(){
	scanf("%d%d",&n,&k);scanf("%s",s);
	rep(i,0,n-1)p[s[i]-'a']=1;
	rep(i,0,25)if(p[i]){
		ans+=i+1;i++;k--;
		if(!k)break;
	}
	if(!k)printf("%d\n",ans);else printf("-1\n");
}