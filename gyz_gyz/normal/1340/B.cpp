#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2010;
const int inf=1e9;
const int mo=998244353;
const string dg[]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
char str[9];int t[N][10],f[N][N];
int main(){int n,k;
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		scanf("%s",str);
		rep(j,0,9){
			rep(l,0,6)if(dg[j][l]!=str[l]){
				if(str[l]=='1'){
					t[i][j]=-1;break;
				}else ++t[i][j];
			}
		}
	}
	rep(i,1,n+1)rep(j,0,k)f[i][j]=-1;
	f[n+1][0]=0;
	dep(i,n,1)rep(j,0,k)dep(l,9,0)
		if(~t[i][l]&&j>=t[i][l]&&~f[i+1][j-t[i][l]]){
			f[i][j]=l;break;
		}
	if(f[1][k]==-1){
		printf("-1\n");return 0;
	}int x=k;
	rep(i,1,n){
		printf("%d",f[i][x]);
		x-=t[i][f[i][x]];
	}printf("\n");
}