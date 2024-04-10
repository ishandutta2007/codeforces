#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,a[1005],b[1005],c[1005],d[1005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i]>>d[i];
	for(int i=1;i<=n;i++){
		int A=a[1]+c[i],B=b[1]+d[i];
		multiset<pr> s;
		for(int j=1;j<=n;j++)s.insert(pr(a[j],b[j]));
		int ok=1;
		for(int j=1;j<=n;j++){
			pr w=pr(A-c[j],B-d[j]);
			if(s.find(w)==s.end()){
				ok=0;
				break;
			}
			else s.erase(s.find(w));
		}
		if(ok)cout<<A<<' '<<B<<'\n',exit(0);
	}
}