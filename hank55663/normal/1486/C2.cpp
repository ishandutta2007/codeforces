#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
bool solve(){
	int n;
	scanf("%d",&n);
	int l=1,r=n;
	printf("? 1 %d\n",n);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	if(x==1){
		int l=1,r=n;
		while(l+1<r){
			int mid=(l+r)/2;
			printf("? %d %d\n",x,mid);
			fflush(stdout);
			int y;
			scanf("%d",&y);
			if(y==x){
				r=mid;
			}
			else{
				l=mid;
			}
		}
		printf("! %d\n",r);
	}
	else if(x==n){
		int l=1,r=n;
		while(l+1<r){
			int mid=(l+r)/2;
			printf("? %d %d\n",mid,x);
			fflush(stdout);
			int y;
			scanf("%d",&y);
			if(y==x){
				l=mid;
			}
			else{
				r=mid;
			}
		}
		printf("! %d\n",l);
	}
	else{
		printf("? %d %d\n",x,n);
		fflush(stdout);
		int y;
		scanf("%d",&y);
		if(y==x){
			int l=x,r=n;
			while(l+1<r){
				int mid=(l+r)/2;
				printf("? %d %d\n",x,mid);
				fflush(stdout);
				int y;
				scanf("%d",&y);
				if(y==x){
					r=mid;
				}
				else{
					l=mid;
				}
			}
			printf("! %d\n",r);
		}
		else{
			int l=1,r=x;
			while(l+1<r){
				int mid=(l+r)/2;
				printf("? %d %d\n",mid,x);
				fflush(stdout);
				int y;
				scanf("%d",&y);
				if(y==x){
					l=mid;
				}
				else{
					r=mid;
				}
			}
			printf("! %d\n",l);
		}
	}
	return true;
}
int main(){
	int t=1;//000000;
    //scanf("%d",&t);
    while(t--)solve();
}