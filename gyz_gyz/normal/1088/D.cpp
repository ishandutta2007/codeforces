#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 200000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a,b,f[40];
void eq(int n){
	dep(j,n,0){
		printf("? %d %d\n",a+(1<<j),b);
		fflush(stdout);int t;scanf("%d",&t);
		if(t==-1)a+=1<<j,b+=1<<j;
	}
	printf("! %d %d\n",a,b);exit(0);
}
int main(){
	dep(i,29,0){
		if(!f[i]){
			printf("? %d %d\n",a,b);
			fflush(stdout);scanf("%d",&f[i]);
			if(f[i]==0)eq(i);
		}
		if(f[i]==1){
			printf("? %d %d\n",a+(1<<i),b);
			int t;fflush(stdout);scanf("%d",&t);
			if(!t){
				a+=1<<i;eq(i-1);
			}
			if(t==1){
				if(i)f[i-1]=1;
				printf("? %d %d\n",a,b+(1<<i));
				int r;fflush(stdout);scanf("%d",&r);
				if(r==1)a+=1<<i;
			}else{
				a+=1<<i;
				printf("? %d %d\n",a,b+(1<<i));
				int r;fflush(stdout);scanf("%d",&r);
				if(r==1){
					b+=1<<i;if(i)f[i-1]=1;
				}else if(i)f[i-1]=-1;
			}
		}else{
			printf("? %d %d\n",a,b+(1<<i));
			int t;fflush(stdout);scanf("%d",&t);
			if(!t){
				b+=1<<i;eq(i-1);
			}
			if(t==-1){
				if(i)f[i-1]=-1;
				printf("? %d %d\n",a+(1<<i),b);
				int r;fflush(stdout);scanf("%d",&r);
				if(r==-1)b+=1<<i;
			}else{
				b+=1<<i;
				printf("? %d %d\n",a+(1<<i),b);
				int r;fflush(stdout);scanf("%d",&r);
				if(r==-1){
					a+=1<<i;if(i)f[i-1]=-1;
				}else if(i)f[i-1]=1;
			}
		}
	}
	printf("! %d %d\n",a,b);
}