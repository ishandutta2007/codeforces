#include<bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N];
bitset<N> b[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	queue<pair<int,int> > q;
	q.push(make_pair(1,n+1));
	for(int i=1;i<=n;++i){
		int l=0,r=0;
		while(!q.empty()&&l==r){
			l=q.front().first,r=q.front().second;
			q.pop();
		}
		int _0=n+1-a[i],_1=a[i];
		if(l<r){
			int k=l;
			for(int j=l;j<=r;++j){
				if(j==r||!_0)b[j][i]=1,--_1;
				else --_0,k=j;	
			}
			q.push(make_pair(l,k));
			q.push(make_pair(k+1,r));
		}
		else l=r=0;
		for(int j=1;j<=n+1;++j){
			if(j>=l&&j<=r)continue;
			if(_1)b[j][i]=1,--_1;
			else --_0;
		}
	}
	printf("%d\n",n+1);
	for(int i=1;i<=n+1;++i){
		for(int j=1;j<=n;++j){
			putchar('0'+b[i][j]);
		}
		putchar('\n');	
	}
	return 0;
}