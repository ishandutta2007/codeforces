#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 100001
#define M 1000000
using namespace std;
int n,m,tot,b[M][26],id[M],c[N],f[N],v[N];
char s[N],a[N][1000];
int r(char x){
	if(x>='a'&&x<='z')return x-'a';
	if(x>='A'&&x<='Z')return x-'A';
	return -1;
}
void wr(int x){
	if(!x)return;wr(f[x]);
	rep(i,0,c[v[x]])printf("%c",a[v[x]][i]);printf(" ");
}
int main(){
	scanf("%d",&n);scanf("%s",s);scanf("%d",&m);
	rep(i,1,m){
		scanf("%s",a[i]);
		c[i]=strlen(a[i])-1;
	}
	rep(i,1,m){int x=0;
		rep(j,0,c[i]){int y=r(a[i][j]);
			if(!b[x][y])b[x][y]=++tot;x=b[x][y];
		}
		id[x]=i;
	}
	rep(i,1,n)f[i]=-1,v[i]=-1;
	rep(i,1,n){int x=0;
		dep(j,i,1){int y=r(s[j-1]);
			if(b[x][y])x=b[x][y];else break;
			if(id[x]&&f[j-1]!=-1){
				f[i]=j-1;v[i]=id[x];break;
			}
		}
	}
	wr(n);
}