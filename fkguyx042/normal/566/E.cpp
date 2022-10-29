#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
#define NC getchar
inline int read(){
	int x=0,f=1;char c=NC();for(;c<'0'||c>'9';c=NC())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=NC())x=x*10+c-'0';return x*f;
}
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Forn(i,a,b) for(int i=(a);i>=(b);i--)
inline int lowbit(int x){
	return x&-x;
}
#define mo 1000000007
inline int power(int a,int b){
	int nowans=1;
	for(;b;b>>=1,a=1ll*a*a%mo)if(b&1)nowans=1ll*nowans*a%mo;
	return nowans;
}
#include<bitset>
#define N 1010
#include<vector>
int n;
bitset<N>s[N];
#define PII pair<int,int>
vector<PII>WatchMeFall[N];
int fa[N*2];
inline int find(int u){
	return u==fa[u]?u:fa[u]=find(fa[u]);
}
inline void merge(int u, int v){
	fa[find(u)]=find(v);
}
#define mk make_pair
#define pb push_back
#define X first
#define Y second
int main() {
	n=read();For(i,0,n-1){
		int k=read();
		For(j,1,k){
			int t=read();
			s[--t].set(i);
		}
	}
	For(i,0,2*n-1)fa[i]=i;
	For(i,0,n-1){
		For(j,i+1,n-1){
			int cnt=(s[i]&s[j]).count();
			if(cnt==1){
				merge(i,j);merge(i+n,j+n);
			}else if(cnt==2&&n>2){
				merge(i,j+n);merge(i+n,j);
			}else{
				WatchMeFall[cnt].push_back(mk(i,j));
			}
		}
	}
	if((int)WatchMeFall[n].size()==(n*(n-1)/2)){
		For(i,2,n){
			printf("%d %d\n",1,i);
		}
	}else if(WatchMeFall[n].size()==1){
		int u=-1,v=-1;
		For(i,0,n-1){
			if((int)s[i].count()==n){
				if(u ==-1)u=i;
				else v=i;
			}
		}
		printf("%d %d\n",u+1,v+1);
		For(i,0,n-1){
			if(i!=u&&i!=v){
				if(find(i)==find(u)){
					printf("%d %d\n",i+1,v+1);
					merge(i,v+n);merge(i+n,v);
				}else{
					printf("%d %d\n",i+1,u+1);
					merge(i,u+n);merge(i+n,u);
				}
			}
		}
	}else{
		Forn(i,n,1){
			for(int j=0;j<=(int)WatchMeFall[i].size()-1;j++){
				int u=WatchMeFall[i][j].X,v=WatchMeFall[i][j].Y;
				if(find(u)==find(v))continue;
				printf("%d %d\n",u+1,v+1);
				merge(u,v+n);merge(u+n,v);
			}
		}
	}
}