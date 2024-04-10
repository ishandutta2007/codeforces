#include<bits/stdc++.h>
using namespace std;
const int M=512,N=1e5+10;
bitset<M>f[M],t;
int a[N];
int main() {
	int n;
	scanf("%d",&n);
	f[0][0]=1;
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		t.reset();
		for(int j=0;j<a[i];j++)
			t|=f[j];
		for(int j=0;j<M;j++)
			if(t[j])f[a[i]][j^a[i]]=1;
	}
	t.reset();
	for(int i=0;i<M;i++)
		t|=f[i];
	cout<<t.count()<<endl;
	for(int i=0;i<M;i++)
		if(t[i])printf("%d ",i);
	puts("");
	return 0;
}