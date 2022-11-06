#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 300000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,k,x,l,r,m;map<int,int>p;
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		scanf("%d",&x);p[x]++;
	}
	l=1;r=n;m=(l+r+1)/2;
	for(;l<r;m=(l+r+1)/2){x=0;
		for(auto i:p)x+=i.second/m;
		if(x<k)r=m-1;else l=m;
	}x=0;
	for(auto i:p)rep(j,1,i.second/m){
		if(++x>k)return 0;printf("%d ",i.first);
	}
}