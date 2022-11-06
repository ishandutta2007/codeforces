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
int n,x,ans;map<int,int>a;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&x);
		a[x]++;if(a[x]>ans)ans=a[x];
	}
	printf("%d\n",n-ans);
}