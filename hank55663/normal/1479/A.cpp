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
int a[100005];
int query(int x){
	//if(x==0||x==)
	if(a[x]!=0)return a[x];
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%d",&a[x]);
	return a[x];
}
/*int cnt;
int query(int x){
    printf("? %d\n",x);
	cnt++;
	return a[x];
}*/
void solve(){
	int n;
	scanf("%d",&n);
  //  for(int i = 1;i<=n;i++)scanf("%d ",&a[i]),printf("%d %d\n",i,a[i]);
   // printf("?\n");
//	for(int i = 1;i<=n;i++)a[i]=i;
//	random_shuffle(a+1,a+n+1);
	a[0]=a[n+1]=1e9;
	int Max=n+1,Min=0;
	while(Max>Min+7){
		int mid1=(Max+Min)/2;//mid2=(Max*2+Min)/3;
		int a=query(mid1);
		int b=query(mid1+1);
		if(a>b){
			Min=mid1;
		}
		else{
			Max=mid1+1;
		}
//		printf("%d %d\n",Max,Min);
	}
	for(int i = Min+1;i<Max;i++){
		if(query(i)<query(i-1)&&query(i)<query(i+1)){
			printf("! %d\n",i);
			fflush(stdout);
			return ;
		}
	}
}
int main(){
    int t=1;//00000;
    //scanf("%d",&t);
    while(t--)solve();
}
/*

*/