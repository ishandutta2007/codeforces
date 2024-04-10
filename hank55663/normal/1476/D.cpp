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
	char c[300005];
	scanf("%s",c);
	int ans[300005];
	fill(ans,ans+300005,0);
	int sum=0;
	for(int i = 0;c[i]!=0;i++){
		if(i==0||c[i]!=c[i-1])sum++;
		else sum=1;
		if(c[i]=='L')ans[i+1]+=sum;
	}
/*	for(int i = 0;i<=n;i++){
		printf("%d ",ans[i]+1);
	}
	printf("\n");*/
	sum=0;
	for(int i = n-1;i>=0;i--){
		if(i==n-1||c[i]!=c[i+1])sum++;
		else sum=1;
		if(c[i]=='R')ans[i]+=sum;
	}
	for(int i = 0;i<=n;i++){
		printf("%d ",ans[i]+1);
	}
	printf("\n");
}
int main(){
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