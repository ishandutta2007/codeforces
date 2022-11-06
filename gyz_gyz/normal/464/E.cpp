#include<cstdio>
#include<vector>
#include<set>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 131072
#define M 10000000
#define mo 1000000007
using namespace std;
vector<int>e[N],w[N];
long long a[M];int L[M],R[M],l[M],r[M];
int n,m,tot,st,ed,x,y,z,sz,bg,tt,tp;
long long P[N];int top[N],fr[N];
int cmp(int x,int y){
	if(L[x]==R[x]){
		if(a[x]==a[y])return 2;return a[x]<a[y];
	}
	if(a[r[x]]==a[r[y]])return cmp(l[x],l[y]);
	return cmp(r[x],r[y]);
}
struct sw{int x,r;
	bool operator < (sw a) const{
		int u=cmp(r,a.r);if(u==2)return x<a.x;else return u==1;
	}
}S,ss;set<sw>s;
inline void nw(int x){a[++tot]=a[x];
	l[tot]=l[x];r[tot]=r[x];L[tot]=L[x];R[tot]=R[x];
}

bool f(int x,int y){bool u=0;
	if(L[x]==y&&R[x]==y){a[x]=1-a[x];return !a[x];}
	if(y<=R[l[x]]){
		nw(l[x]);l[x]=tot;if(f(l[x],y))y=L[r[x]];
	}
	if(y>=L[r[x]]){
		nw(r[x]);r[x]=tot;u=f(r[x],y);
	}
	a[x]=(a[r[x]]*P[R[r[x]]-L[r[x]]+1]+a[l[x]])%mo;return u;
}
void wr(int x,int y){
	if(x==st){printf("%d\n%d",y,x);return;}
	wr(fr[x],y+1);printf(" %d",x);
}
int main(){
	scanf("%d%d\n",&n,&m);
	if(n==1){printf("0\n1\n1\n");return 0;}
	rep(i,1,m){
		scanf("%d%d%d",&x,&y,&z);
		e[x].push_back(y);w[x].push_back(z+1);
		e[y].push_back(x);w[y].push_back(z+1);
	}
	scanf("%d%d",&st,&ed);P[0]=1;
	L[1]=1;R[1]=N;tot=N*2-1;top[st]=1;
	rep(i,1,N-1){
		L[i*2]=L[i];R[i*2]=(L[i]+R[i])/2;
		L[i*2+1]=R[i*2]+1;R[i*2+1]=R[i];
		l[i]=i*2;r[i]=i*2+1;
	}
	rep(i,1,N-1)P[i]=P[i-1]*2%mo;
	rep(i,1,n)if(i!=st){
		nw(1);top[i]=tot;f(top[i],100100);bg=a[top[i]];
	}
	rep(i,1,n){S.x=i;S.r=top[i];s.insert(S);}
	rep(i,1,n){
		S=*s.begin();s.erase(S);sz=e[S.x].size()-1;
		rep(j,0,sz){tt=e[S.x][j];
			nw(top[S.x]);tp=tot;f(tp,w[S.x][j]);
			if(cmp(tp,top[tt])==1){ss.x=tt;ss.r=top[tt];fr[tt]=S.x;
				s.erase(ss);top[tt]=tp;ss.r=tp;s.insert(ss);
			}
		}
	}
	if(a[top[ed]]==bg){printf("-1\n");return 0;}
	printf("%I64d\n",a[top[ed]]);wr(ed,1);
}