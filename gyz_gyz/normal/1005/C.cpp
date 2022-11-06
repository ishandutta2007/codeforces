#include<cstdio>
#include<map>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 1000000
using namespace std;
map<int,int>p;
int a[N],n,u,t,ans;
int main(){
	scanf("%d\n",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);p[a[i]]++;
	}
	rep(i,1,n){u=1;
		rep(j,1,30){t=(1<<j)-a[i];
			if((t>0)&&(p.count(t))){
				if((a[i]==t)&&(p[t]<2))continue;
				u=0;break;
			}
		}
		if(u)ans++;
	}
	printf("%d\n",ans);
}