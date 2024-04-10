#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

int n;
#define Maxn 2005
int b[Maxn],c[Maxn],at;
int query(int len){
	printf("? 1 %d\n",len);
	printf("%d\n",at);
	rep(i,1,len)printf("%d ",c[i]);puts("");fflush(stdout);
	int x;scanf("%d",&x);return x;
}
void Find(int l,int r){
    if(l==r){
    	b[l]=1;
    	return;
	}	
	int mid=(l+r)>>1;
	rep(i,l,mid)c[i-l+1]=i;
	if(query(mid-l+1)!=0)Find(l,mid);
	else Find(mid+1,r);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);at=2;b[1]=0;
		rep(i,2,n){
			printf("? 1 %d\n",i-1);
			printf("%d\n",i);
			rep(j,1,i-1)printf("%d ",j);puts("");fflush(stdout);
			int x;scanf("%d",&x);
			if(x!=0){
				at=i;
				break;
			}
			b[i]=0;
		}
		b[at]=1;
		rep(j,at+1,n){
			printf("? 1 1\n");
			printf("%d\n%d\n",at,j);fflush(stdout);
			scanf("%d",&b[j]);
		}
		Find(1,at-1);
	    int cnt=0;rep(i,1,n)if(!b[i])cnt++;
		printf("! %d ",cnt);
		rep(i,1,n)if(!b[i])printf("%d ",i);puts("");fflush(stdout);
	}
	return 0;
}