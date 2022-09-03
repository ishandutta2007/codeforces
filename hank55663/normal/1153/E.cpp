#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> r,c;
	for(int i = 1;i<n;i++){
		printf("? 1 1 %d %d\n",i,n);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if(x&1){
			r.pb(i);
		}
	}
	for(int i = 1;i<n;i++){
		printf("? 1 1 %d %d\n",n,i);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if(x&1){
			c.pb(i);
		}
	}
	if(r.size()&&c.size()){
		printf("? 1 1 %d %d\n",r[0],c[0]);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if(x&1)
		printf("! %d %d %d %d\n",r[0],c[0],r.back()+1,c.back()+1);
		else
		printf("! %d %d %d %d\n",r.back()+1,c[0],r[0],c.back()+1);
		fflush(stdout);
	}
	else if(r.size()){
		int Min=0,Max=n;
		while(Min+1<Max){
			int mid=(Max+Min)/2;
			printf("? 1 1 %d %d\n",r[0],mid);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			if(x&1){
				Max=mid;
			}
			else{
				Min=mid;
			}
		}
		printf("! %d %d %d %d\n",r[0],Max,r.back()+1,Max);
		fflush(stdout);
	}
	else if(c.size()){
		int Min=0,Max=n;
		while(Min+1<Max){
			int mid=(Max+Min)/2;
			printf("? 1 1 %d %d\n",mid,c[0]);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			if(x&1){
				Max=mid;
			}
			else{
				Min=mid;
			}
		}
		printf("! %d %d %d %d\n",Max,c[0],Max,c.back()+1);
		fflush(stdout);
	}
}