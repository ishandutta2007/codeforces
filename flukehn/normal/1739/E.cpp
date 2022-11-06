#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int inf=~0u>>2;
const int N=2e5+11;
char s[2][N];
typedef int arr[2][2];
arr f,g;
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	while(cin>>n){
		cin>>s[0]>>s[1];
		For(i,0,2)For(j,0,n) s[i][j]-='0';
		s[0][n]=s[1][n]=0;
		f[0][0]=0;
		f[0][1]=1;
		f[1][0]=inf;
		f[1][1]=inf;
		For(i,0,n) {
			memcpy(g,f,sizeof(g));
			memset(f,0x3f,sizeof(f));
			For(x,0,2) {
				int y=x^1;
				For(w,0,2)For(t,0,2){
					if(s[y][i] && !w){
						
						f[x][t]=min(f[x][t], g[x][w]+1+t);
						if(t==1)f[y][t]=min(f[y][t], g[x][w]+s[x][i+1]);
					}else{
						f[x][t]=min(f[x][t], g[x][w]+t);
					}
				}
			}
		}
		int tot=0;
		For(i,0,2)For(j,0,n) tot+=s[i][j];
		cout<<tot-min({f[0][0],f[1][0],f[0][1],f[1][1]})<<'\n';
	}
}