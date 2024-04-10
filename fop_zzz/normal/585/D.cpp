#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define cross(i,k) for (register int i=first[k];i;i=last[i])
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
inline ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 30;
int n,a[N],b[N],c[N];
struct node{
	int x;
	char c[13][2];
}tmp;
map<pa,node>m;
int cnt;
char s[N][2];
inline void dfs(int k,int l,int r,int A,int B,int C){
	if (k>r){
		pa x=mp(A-B,B-C);
		if (!m.count(x)){
			tmp.x=A;
			For(i,l,r) tmp.c[i][0]=s[i][0],tmp.c[i][1]=s[i][1];
			m[x]=tmp;
		} if (m[x].x<A){
			tmp.x=A;
			For(i,l,r) tmp.c[i][0]=s[i][0],tmp.c[i][1]=s[i][1];
			m[x]=tmp;
		}
		return;
	}
	s[k][0]='L',s[k][1]='M',dfs(k+1,l,r,A+a[k],B+b[k],C);
	s[k][0]='L',s[k][1]='W',dfs(k+1,l,r,A+a[k],B,C+c[k]);
	s[k][0]='M',s[k][1]='W',dfs(k+1,l,r,A,B+b[k],C+c[k]);
}
int ans;
char Ans[N][2];
inline void Dfs(int k,int l,int r,int A,int B,int C){
	if (k>r){
		pa x=mp(B-A,C-B);
		if (!m.count(x)) return;
		if (m[x].x+A>ans){
			tmp=m[x],ans=tmp.x+A;
			For(i,0,n/2-1) Ans[i][0]=tmp.c[i][0],Ans[i][1]=tmp.c[i][1];
			For(i,l,r) Ans[i][0]=s[i][0],Ans[i][1]=s[i][1];
		}
		return;
	}
	s[k][0]='L',s[k][1]='M',Dfs(k+1,l,r,A+a[k],B+b[k],C);
	s[k][0]='L',s[k][1]='W',Dfs(k+1,l,r,A+a[k],B,C+c[k]);
	s[k][0]='M',s[k][1]='W',Dfs(k+1,l,r,A,B+b[k],C+c[k]);
}
int main(){
	n=read();
	For(i,0,n-1) a[i]=read(),b[i]=read(),c[i]=read();
	ans=-2e9,dfs(0,0,n/2-1,0,0,0),Dfs(n/2,n/2,n-1,0,0,0);
	if (ans==-2e9) return puts("Impossible"),0;
	For(i,0,n-1) printf("%c%c\n",Ans[i][0],Ans[i][1]);
}