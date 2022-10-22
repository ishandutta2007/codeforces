#include <bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a); (i) < b; ++(i))

using namespace std;

int s[200005], b[200005];

int main(){
	int n, w;
	scanf("%d%d", &n, &w);
	rep(i,0,n){
		scanf("%d", b+i);
	}
	rep(i,0,w){
		scanf("%d", s+i);
	}
	rep(i,0,w-1)
		s[i]=s[i+1]-s[i];
	rep(i,0,n-1)
		b[i]=b[i+1]-b[i];
	int ans=0;
	s[w-1]=2000000000;
	b[n-1]=-2000000000;
	vector<int> a(w+1);
	a[0]=-1;
	for(int i=1; i <= w; ++i){
		a[i]=a[i-1];
		while(a[i] >= 0 && s[i-1] != s[a[i]])
			a[i]=a[a[i]];
		++a[i];
	}
	int p=-1;
	for(int i=0; i < n; ++i){
		++p;
		while(p >= 0 && b[i] != s[p])
			p=a[p];
		if(p == w-2)
			++ans;
	}
	printf("%d\n", ans);
}