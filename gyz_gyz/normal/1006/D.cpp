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
#define N 1000000
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
int n,ans;char a[N],b[N];
int main(){
	scanf("%d",&n);scanf("%s",a+1);scanf("%s",b+1);
	rep(i,1,(n-1)/2+1){
		if((i==n-i+1)&&(a[i]!=b[i]))ans++;
		if((a[i]==a[n-i+1])&&(b[i]==b[n-i+1]))continue;
		if((a[i]==b[i])&&(a[n-i+1]==b[n-i+1]))continue;
		if((a[i]==b[n-i+1])&&(b[i]==a[n-i+1]))continue;ans++;
		if(a[i]==b[i])continue;
		if(a[i]==b[n-i+1])continue;
		if(b[i]==a[n-i+1])continue;
		if(b[i]==b[n-i+1])continue;
		if(a[n-i+1]==b[n-i+1])continue;ans++;
	}
	printf("%d\n",ans);
}