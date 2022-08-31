#include<bits/stdc++.h>
#define maxn 505050
#define F first
#define S second

using namespace std;
typedef pair<int,int> pi;
pi c[maxn];
int a[maxn],b[maxn],l,r,mid,s,t,n,L;

bool check(int x){
	for (int i=0;i<n;i++){
		c[i].F=lower_bound(b,b+n*2+1,a[i]-x)-b;
		c[i].S=lower_bound(b,b+n*2+1,a[i]+x+1)-b;
	}
	s=c[0].F; t=c[0].S; 
	for (int i=1;i<n;i++){
		if (t<=s) return false;
		s=max(s+1,c[i].F);
		t=min(t+1,c[i].S);
	}
	return s<t;
}

int main(){
	cin >> n >> L;
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++) scanf("%d",&b[i]);
	sort(b,b+n);
	for (int i=0;i<n;i++) b[i+n]=b[i]+L; b[n*2]=L*2;
	for (int i=0;i<n;i++) if (a[i]<=L/2) a[i]+=L;
	sort(a,a+n);
	l=-1; r=L/2;
	while (r-l>1){
		mid=(l+r)/2;
		if (check(mid)) r=mid; else l=mid;
	}
	cout << r << endl;
	return 0;
}