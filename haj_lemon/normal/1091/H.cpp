#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
int a[N],na,n,f,x[N+10],p,q,y,ans;
bitset<N+10> v,b[110];
bool pa(int x){for (int i=2;i*i<=x;i++)if (x%i==0)return 0;return 1;}
void pre(){
	for (int i=2;i<=N;i++) if (pa(i)){a[++na]=i;v[i]=1;}
	for (int i=1;i<=na;i++)
		for (int j=i;j<=na&&1ll*a[i]*a[j]<=N;j++)v[a[i]*a[j]]=1;
}
int main(){
	pre();read(n);read(f);v[f]=0;x[0]=0;b[0]=v;
	for (int i=1;i<=N;i++){while(b[x[i]][i])x[i]++;b[x[i]]|=v<<i;}
	for (int i=1;i<=n;i++){read(p);read(q);read(y);ans^=x[q-p-1]^x[y-q-1];}
	if (ans){puts("Alice");puts("Bob");}else{puts("Bob");puts("Alice");}
	return 0;
}