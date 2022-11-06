#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=1e9+7;
int a[N],b[7];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(x==4)a[i]=1;
		if(x==8)a[i]=2;
		if(x==15)a[i]=3;
		if(x==16)a[i]=4;
		if(x==23)a[i]=5;
		if(x==42)a[i]=6;
	}
	rep(i,1,n){
		if(a[i]==1)++b[1];
		else b[a[i]]=min(b[a[i]-1],b[a[i]]+1);
	}
	printf("%d\n",n-b[6]*6);
}