#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 3000000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,x,y,z,a[N];string s;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&x);a[x]=i;
		if(x!=i)y=1;
	}
	
	if(!y){
		printf("%d\n",n);
		rep(i,1,n){
			rep(j,1,n)printf(".");printf("\n");
		}return 0;
	}
	printf("%d\n",n-1);a[n]=n+1;
	rep(i,1,n)if(i&1){
		rep(i,1,n)if(!a[i])a[i]=n+1;
		for(x=1;(a[x]==n+1||a[x]==x)&&x<=n;x++)printf(".");
		y=x;z=a[x];a[x]=n+1;
		while(x<=n){printf("\\");
			for(x++;x<z;x++)printf(".");
			y=x;swap(a[x],z);
		}printf("\n");
	}else{s.clear();
		rep(i,1,n)if(a[i]==n+1)a[i]=0;
		for(x=n;(!a[x]||a[x]==x)&&x;x--)s="."+s;
		y=x;z=a[x];a[x]=0;
		while(x){s="/"+s;
			for(x--;x>z;x--)s="."+s;
			y=x;swap(a[x],z);
		}
		cout<<s<<'\n';
	}
}