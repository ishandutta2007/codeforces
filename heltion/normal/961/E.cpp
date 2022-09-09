#include<bits/stdc++.h>
#define N 200005
using namespace std;
int id[N],a[N],f[N],n;long long ans;
void add(int x){for (;x<=n;x+=x&-x) f[x]++;}
int ask(int x){int s=0;for (;x;x-=x&-x) s+=f[x];return s;}
int cmp(const int &A,const int &B){return a[A]<a[B];}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);int p=0;
	for (int i=2;i<=n;i++){
		int j=min(i-1,a[i]);
		for (;p<n&&a[id[p+1]]<i;)
			add(id[++p]);
		ans+=j-ask(j);
	}
	printf("%lld\n",ans);
}