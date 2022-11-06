#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 1000
#define ll long long
#define mo 2147483647
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
const char ch[3]={'0','a','A'};
int T,l,a[3],w[N];char s[N];
void sol(){
	scanf("%s",&s);a[0]=a[1]=a[2]=0;
	for(l=0;s[l];l++){
		if((s[l]>='0')&&(s[l]<='9'))w[l]=0,a[0]++;
		if((s[l]>='a')&&(s[l]<='z'))w[l]=1,a[1]++;
		if((s[l]>='A')&&(s[l]<='Z'))w[l]=2,a[2]++;
	}
	if(a[0]&&a[1]&&a[2]){
		rep(i,0,l-1)printf("%c",s[i]);
		printf("\n");return;
	}
	rep(i,0,l-1)rep(j,0,2){
		a[w[i]]--;a[j]++;
		if(a[0]&&a[1]&&a[2]){
			rep(k,0,i-1)printf("%c",s[k]);
			printf("%c",ch[j]);
			rep(k,i+1,l-1)printf("%c",s[k]);
			printf("\n");return;
		}
		a[w[i]]++;a[j]--;
	}
	rep(i,0,l-2)rep(j1,0,1)rep(j2,j1+1,2){
		a[w[i]]--;a[w[i+1]]--;a[j1]++;a[j2]++;
		if(a[0]&&a[1]&&a[2]){
			rep(k,0,i-1)printf("%c",s[k]);
			printf("%c%c",ch[j1],ch[j2]);
			rep(k,i+2,l-1)printf("%c",s[k]);
			printf("\n");return;
		}
		a[w[i]]++;a[w[i+1]]++;a[j1]--;a[j2]--;
	}
}
int main(){
	for(scanf("%d",&T);T;T--)sol();
}