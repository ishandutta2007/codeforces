#include <bits/stdc++.h>
using namespace std;

#define N 300010
pair< string,int> a[N * 2];
int b[N * 2],n,p[N * 2];
int main(){
	scanf("%d",&n);
	for(int i =1;i<=n;i++){
		cin>>a[i*2-1].first;
		a[i*2-1].second=i*2-1;
		cin>>a[i*2].first;
		a[i*2].second=i*2;
	}
	sort(a+1,a+n*2+1);
	for(int i=1;i<=2*n;i++)	b[a[i].second]=i;
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	int now = 0;
	for(int i=1;i<=n;i++){
		int l=b[p[i]*2-1],r=b[p[i]*2];
		if(l>r)swap(l,r);
		if(l>now)	now=l;
		else	if(r>now)	now=r;
		else{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}