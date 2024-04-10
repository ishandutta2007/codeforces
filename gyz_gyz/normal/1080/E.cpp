#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 300
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,ans,p[N],od[N],v[N][26];char s[N][N];
bool cp(int x,int y){
	if(x<1||y>n||od[x]>1||od[y]>1)return 0;
	rep(i,0,25)if(v[x][i]!=v[y][i])return 0;return 1;
}
void sol(){int j=0;
	rep(i,1,n){
		if(i>j+p[j]){j=i;p[i]=0;
			while(cp(i-p[i]-1,i+p[i]+1))++p[i];
		}else{
			if(p[j*2-i]!=p[j]+j-i)p[i]=min(p[j*2-i],p[j]+j-i);
			else{p[i]=p[j*2-i];j=i;
				while(cp(i-p[i]-1,i+p[i]+1))++p[i];
			}
		}
		if(od[i]<=1)ans+=p[i]+1;
	}j=0;
	rep(i,1,n){
		if(i>=j+p[j]){j=i;p[i]=0;
			while(cp(i-p[i]-1,i+p[i]))++p[i];
		}else{
			if(p[j*2-i]!=p[j]+j-i)p[i]=min(p[j*2-i],p[j]+j-i);
			else{p[i]=p[j*2-i];j=i;
				while(cp(i-p[i]-1,i+p[i]))++p[i];
			}
		}ans+=p[i];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,m){
		rep(j,1,n){od[j]=0;
			rep(k,0,25)v[j][k]=0;
		}
		rep(j,i,m){
			rep(k,1,n)if((++v[k][s[k][j]-'a'])&1)od[k]++;else od[k]--;sol();
		}
	}
	printf("%d\n",ans);
}