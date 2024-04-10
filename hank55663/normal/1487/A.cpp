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
void solve(){
	int n;
	scanf("%d",&n);
	int a[105];
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	a[n]=a[0]+1;
	for(int i = 0;i<=n;i++){
		if(a[i]!=a[0]){
			printf("%d\n",n-i);
			return ;
		}
	}
}
int main(){
    int t=1;00000;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*

*/