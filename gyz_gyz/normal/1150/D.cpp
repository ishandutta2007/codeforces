#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
const int N=1e5+10;
const ll mo=1e9+7;
const ll inf=1e9;
const ll Inf=1e18;
int n,m,l1,l2,l3,nt[N][26],a[255][255][255];
char s[N],s1[N],s2[N],s3[N];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	rep(i,0,25)nt[n+1][i]=n+1;
	dep(i,n+1,1)rep(j,0,25)nt[i-1][j]=j==s[i]-'a'?i:nt[i][j];
	rep(i,1,m){char op;int x;
		scanf("\n%c %d",&op,&x);
		if(op=='+'){char c;
			scanf(" %c",&c);
			if(x==1){s1[++l1]=c;
				rep(j,0,l2)rep(k,0,l3){
					a[l1][j][k]=nt[a[l1-1][j][k]][c-'a'];
					if(j)a[l1][j][k]=min(a[l1][j][k],nt[a[l1][j-1][k]][s2[j]-'a']);
					if(k)a[l1][j][k]=min(a[l1][j][k],nt[a[l1][j][k-1]][s3[k]-'a']);
				}
			}
			if(x==2){s2[++l2]=c;
				rep(j,0,l1)rep(k,0,l3){
					a[j][l2][k]=nt[a[j][l2-1][k]][c-'a'];
					if(j)a[j][l2][k]=min(a[j][l2][k],nt[a[j-1][l2][k]][s1[j]-'a']);
					if(k)a[j][l2][k]=min(a[j][l2][k],nt[a[j][l2][k-1]][s3[k]-'a']);
				}
			}
			if(x==3){s3[++l3]=c;
				rep(j,0,l1)rep(k,0,l2){
					a[j][k][l3]=nt[a[j][k][l3-1]][c-'a'];
					if(j)a[j][k][l3]=min(a[j][k][l3],nt[a[j-1][k][l3]][s1[j]-'a']);
					if(k)a[j][k][l3]=min(a[j][k][l3],nt[a[j][k-1][l3]][s2[k]-'a']);
				}
			}
		}else{
			if(x==1)--l1;
			if(x==2)--l2;
			if(x==3)--l3;
		}
		printf("%s\n",a[l1][l2][l3]<=n?"YES":"NO");
	}	
}