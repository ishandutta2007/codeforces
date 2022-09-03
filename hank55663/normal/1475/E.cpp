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
int C[1005][1005];
int mod=1e9+7;
void build(){
	for(int i = 0;i<1005;i++){
		C[i][0]=C[i][i]=1;
		for(int j = 1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
}
bool solve(){
	int n,k;
	scanf("%d %d",&n,&k);
	int cnt[1005];
	int a[1005];
	fill(cnt,cnt+n+1,0);
	for(int i = 0;i<n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
	sort(a,a+n);
	reverse(a,a+n);
	int tot=0;
	for(int i = 0;i<k;i++){
		if(a[i]==a[k-1])tot++;
	}
	printf("%d\n",C[cnt[a[k-1]]][tot]);
}
int main(){
	build();
    int t=1;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/