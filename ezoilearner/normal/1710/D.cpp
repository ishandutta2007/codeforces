#include<bits/stdc++.h>
using namespace std;
 
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
 
typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second
 
inline void rd(int &x){
    x=0;char ch=getchar();int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}
 
#define Maxn 5010

int n; bool link[Maxn][Maxn]; char s[Maxn];

void solve(int l,int r){
	for(int l0=l+1,r0=r;l0<=r;l0=r0+1,r0=r){
		while(!link[l0][r0])--r0;
		solve(l0,r0);
		for(int i=l0;i<=r0;++i)
			if(link[l][i]){
				printf("%d %d\n",l,i);
				goto NXT;
			}
		if(!link[l][l0-1]){
			printf("%d %d\n",l,l0);
			goto NXT;
		}
		for(int i=r0+1;i<=r;++i)
			if(link[l][i]){
				printf("%d %d\n",r0,i);
				break;
			}
		NXT:;
	}
}

void work(){
	rd(n);
	rep(i,1,n){
		scanf("%s", s+i);
		rep(j,i,n) link[i][j]=s[j]=='1';
	}
	solve(1,n);
}

int main(){
	int T;
	rd(T);
	while(T--) work();
}