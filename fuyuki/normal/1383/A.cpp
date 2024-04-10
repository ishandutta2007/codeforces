#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e5+100,INF=0x3f3f3f3f;
char a[N],b[N];
int T,n,ans,flag,d[30],e[30][30];
int main(){
	for(scanf("%d",&T);T--;){
		FOR(i,0,25)FOR(j,0,25)e[i][j]=0;
		ans=0,scanf("%d%s%s",&n,a+1,b+1);
		FOR(i,1,n)if(a[i]!=b[i]){
			if(a[i]>b[i]){ans=-1;goto end;}
			e[a[i]-'a'][b[i]-'a']++;
		}
		FOR(i,0,25){
			FOR(j,i+1,25)if(e[i][j]){
				ans++;
				FOR(k,j+1,25)if(e[i][k])
					e[j][k]+=e[i][k],e[i][k]=0;
			}
		}
		end:cout<<ans<<'\n';
	}
	return 0;
}