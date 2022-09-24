#include<bits/stdc++.h>
using namespace std;
int n,q,a[100005],s[2];
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[a[i]]++;
	while(q--){
		int o,x;
		scanf("%d%d",&o,&x);
		if(o==2)printf("%d\n",x<=s[1]?1:0);
		else s[a[x]]--,a[x]=1-a[x],s[a[x]]++;
	}
}