#include<bits/stdc++.h>
using namespace std;
set<int> b;
map<int,int> a;
int m,n,x,y,sum,an[200010];
int main(){
	scanf("%d %d %d",&n,&m,&x);
	for (int i=1;i<=n;i++){scanf("%d",&y);a[y]=i;b.insert(y);}
	while (!b.empty()){
		sum++;
		set<int>::iterator p=b.begin();
		while (p!=b.end()){
			an[a[*p]]=sum;b.erase(p);
			p=b.upper_bound(*p+x);
		}
	}
	cout<<sum<<endl;
	for (int i=1;i<=n;i++) printf("%d ",an[i]);cout<<endl;
	return 0;
}