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
#define N 262144
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,mx,mi,x;
int main(){
	scanf("%d",&n);mi=inf;
	rep(i,1,n){
		scanf("%d",&x);
		if(x>mx)mx=x;
		if(x<mi)mi=x;
	}
	printf("%d",mx-mi-n+1);
}