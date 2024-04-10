#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
int main(){
	int n;
	scanf("%d",&n);
	int a[100005];
	int pre[200005];
	pre[0]=0;
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=pre[i-1]+a[i];
	}
	for(int i = n+1;i<=2*n;i++){
		pre[i]=pre[i-1]+a[i-n];
	}
	int s,f;
	scanf("%d %d",&s,&f);
	int tot=f-s;
	int ans=0;
	int ansi;
	for(int i =1;i<=n;i++){
		if(pre[i+tot-1]-pre[i-1]>ans){
			ans=pre[i+tot-1]-pre[i-1];
			int aansi=s - (i-1) + n;
			aansi=(aansi-1)%n+1;
			ansi=aansi;
		}
		if(pre[i+tot-1]-pre[i-1]==ans){
			int aansi=s - (i-1) + n;
			aansi=(aansi-1)%n+1;
			ansi=min(aansi,ansi);
		}
	}
	//ansi = s - (ansi-1) + n;
	printf("%d\n",ansi);
}