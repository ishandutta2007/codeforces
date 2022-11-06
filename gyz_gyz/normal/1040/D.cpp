#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 300000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
ll n,l,r;int k,x;char s[9];
int main(){
	scanf("%I64d%d",&n,&k);l=1;r=n;srand(time(0));
	for(;;){
		if(r-l>k*4){
			printf("%I64d %I64d\n",l,(l+r)/2);
			fflush(stdout);scanf("%s",s);
			if(s[0]=='Y'){
				l=max(l-k,1ll);r=min((l+r)/2+k,n);
			}else{
				l=max((l+r)/2+1-k,1ll);r=min(r+k,n);
			}
		}else{
			x=rand()%(r-l+1);
			printf("%I64d %I64d\n",l+x,l+x);
			fflush(stdout);scanf("%s",s);
			if(s[0]=='Y')return 0;
			l=max(l-k,1ll);r=min(r+k,n);
		}
	}
}