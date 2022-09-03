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
	//int h[105];
	LL tot=0;
	int ok=1;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		tot+=x;
		tot-=i;
		if(tot<0){
			ok=0;
			//printf("NO\n");
			//return true;
		}
	}
	if(ok){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return true;
}
int main(){
	int t=1;//000000;
    scanf("%d",&t);
    while(t--)solve();
}