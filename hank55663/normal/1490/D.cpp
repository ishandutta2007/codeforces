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
int d[105];
int a[105];
void go(int l,int r,int dd){
	if(l>r)return;
	int Max=0,Maxi=0;
	for(int i =l;i<=r;i++){
		if(a[i]>Max){
			Max=a[i];
			Maxi=i;
		}
	}
	d[Maxi]=dd;
	go(l,Maxi-1,dd+1);
	go(Maxi+1,r,dd+1);
}
bool solve(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)scanf("%d",&a[i]);
	go(0,n-1,0);
	for(int i = 0;i<n;i++){
		printf("%d ",d[i]);
	}
	printf("\n");
	return true;
}
int main(){
	int t=1;//000000;
    scanf("%d",&t);
    while(t--)solve();
}