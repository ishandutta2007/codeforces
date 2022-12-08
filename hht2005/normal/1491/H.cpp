#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],pos[N],L[N],R[N];
long long f[N];
#define A(x) max(a[x]-f[pos[x]],1ll)
#define B(x) (f[pos[x]]>=T?A(x):b[x])
void updata(int i) {
	for(int j=L[i];j<=R[i];j++)
		if(A(j)<L[i])b[j]=A(j);
		else b[j]=b[A(j)];
}
int main() {
	int n,q,op,l,r,x;
	scanf("%d%d",&n,&q);
	int T=sqrt(n);
	for(int i=2;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++) {
		if((i-1)%T==0) {
			pos[i]=pos[i-1]+1;
			L[pos[i]]=i;
		} else pos[i]=pos[i-1];
		R[pos[i]]=i;
	}
	for(int i=1;i<=pos[n];i++)
		updata(i);
	while(q--) {
		scanf("%d%d%d",&op,&l,&r);
		if(op==2) {
			while(B(l)!=B(r)) {
				if(pos[l]<pos[r])swap(l,r);
				l=B(l);
			}
			while(A(l)!=A(r)) {
				if(A(l)<A(r))swap(l,r);
				l=A(l);
			}
			if(l==r)printf("%d\n",l);
			else printf("%lld\n",A(l));
		} else {
			scanf("%d",&x);
			if(pos[l]==pos[r]) {
				for(int i=l;i<=r;i++)
					a[i]=max(a[i]-x,1);
				updata(pos[l]);
			} else {
				for(int i=l;pos[i]==pos[l];i++)
					a[i]=max(a[i]-x,1);
				updata(pos[l]);
				for(int i=r;pos[i]==pos[r];i--)
					a[i]=max(a[i]-x,1);
				updata(pos[r]);
				for(int i=pos[l]+1;i<=pos[r]-1;i++) {
					f[i]+=x;
					if(f[i]<T)updata(i);
				}
			}
		}
	}
	return 0;
}