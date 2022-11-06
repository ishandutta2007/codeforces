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
int n,x,y,z,ans,a[N];map<int,int>p;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&x);
		p[x]++;a[p[x]]++;
	}
	rep(i,1,n){
		if(!a[i])break;x=i;y=1;z=i;
		while(!(z&1)){z/=2;
			if(a[z]<=y)break;
			x+=z;y++;
		}
		ans=max(x,ans);
	}
	printf("%d\n",ans);
}