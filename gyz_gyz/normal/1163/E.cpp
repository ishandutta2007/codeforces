#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int inf=1e9;
const int N=3e5+10;
int n,t[N],ans[N],s[N],a[20],b[20];
bool ck(int m){
	rep(i,0,m)a[i]=b[i]=0;
	rep(i,1,n)if(s[i]<(1<<(m+1))){
		int x=s[i],y=0;
		dep(j,m,0)if((x>>j)&1){
			if(!a[j]){
				a[j]=x;b[j]=y^(1<<j);break;
			}else x^=a[j],y^=b[j];
		}
	}
	rep(i,0,m)if(!a[i])return 0;return 1;
}
int main(){int m=0;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&s[i]);
	dep(i,19,0)if(ck(i)){
		m=i+1;break;
	}
	printf("%d\n",m);ans[0]=0;
	rep(i,0,m-1)rep(j,0,(1<<i)-1)ans[(1<<(i+1))-j-1]=ans[j]^(1<<i);
	rep(i,0,(1<<m)-1){
		int x=i,y=0;
		dep(j,m-1,0)if((x>>j)&1)x^=a[j],y^=b[j];
		t[y]=i;
	}
	rep(i,0,(1<<m)-1)printf("%d ",t[ans[i]]);
}