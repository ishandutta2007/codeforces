#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
unordered_map<int,int> c;
int m,n,ansn,a[100010],b[100010],p;
int main(){
	scanf("%d %d",&n,&p);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d %d",&m,&p);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	if (m==1&&n==1) ansn=2;
	for (int i=2;i<INF;i*=2){
		c.clear();
		for (int j=1;j<=n;j++){
			c[a[j]%i]++;
			ansn=max(ansn,c[a[j]%i]);
		}
		for (int j=1;j<=m;j++){
			c[(b[j]+i/2)%i]++;
			ansn=max(ansn,c[(b[j]+i/2)%i]);
		}
	}
	cout<<ansn<<endl;
	return 0;
}