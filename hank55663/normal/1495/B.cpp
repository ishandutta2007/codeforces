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
	int p[100005];
	for(int i = 0;i<n;i++){
		scanf("%d",&p[i]);
	}
	int a[100005],b[100005];
	MEM(a);
	MEM(b);
	int Max=0;
	for(int i = 1;i<n;i++){
		if(p[i]>p[i-1])a[i]=a[i-1]+1;
		else a[i]=0;
		Max=max(Max,a[i]);
	}
	for(int i = n-2;i>=0;i--){
		if(p[i]>p[i+1])b[i]=b[i+1]+1;
		else b[i]=0;
		Max=max(Max,b[i]);
	}
	int cnt=0;
	for(int i = 0;i<n;i++){
		if(a[i]==Max)cnt++;
		if(b[i]==Max)cnt++;
	}
	if(cnt>=3){
		printf("0\n");
		return true;
	}
	int ans=0;
	for(int i = 1;i<n-1;i++){
		if(a[i]==Max&&b[i]==Max&&Max%2==0)ans++;
	/*	if(Max%2==0&&cnt==1){
		if(a[i]==Max&&b[i]==Max-1){
			ans++;
		}
		if(a[i]==Max-1&&b[i]==Max){
			ans++;
		}
		}*/
	}
	printf("%d\n",ans);
}
/*
5 5
2 8
*/
int main(){
		//MEMS(dp);
	int t=1;//000000;//000000;
    //scanf("%d",&t);
    //MEMS(dp);
	while(t--)solve();
}