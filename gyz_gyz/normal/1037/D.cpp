#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
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
int n,x,y,t,a[N];
set<int>s[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		s[x].insert(y);s[y].insert(x);
	}
	rep(i,1,n)scanf("%d",&a[i]);t=2;
	if(a[1]!=1){
		printf("No");return 0;
	}
	rep(i,1,n){
		while(!s[a[i]].empty()){
			if(t>n)break;
			auto x=s[a[i]].lower_bound(a[t]);
			if((x==s[a[i]].end())||((*x)!=a[t])){
				printf("No");return 0;
			}
			s[a[t]].erase(s[a[t]].lower_bound(a[i]));
			s[a[i]].erase(x);t++;
		}
		if(t>n)break;
	}
	printf("Yes");
}