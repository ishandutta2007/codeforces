#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 262144
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,x,y,a[8];char ch[9];
int main(){
	scanf("%d",&n);rep(i,0,7)a[i]=inf;
	rep(i,1,n){
		scanf("%d %s",&y,ch);x=0;
		rep(j,0,2){
			if(!ch[j])break;
			x+=1<<(ch[j]-'A');
		}
		a[x]=min(a[x],y);
	}
	rep(i,0,7)rep(j,0,7)a[i|j]=min(a[i|j],a[i]+a[j]);
	if(a[7]==inf)printf("-1");else printf("%d",a[7]);
}