#include<bits/stdc++.h>
using namespace std;
int pl[500005],mn[500005],n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)mn[i]=i;
	for(int i=2;i<=n;i++){
		pl[i]=i;
		if(mn[i]!=i)continue;
		for(int j=i;j<=n;j+=i)mn[j]=min(mn[j],i);
	}
	for(int i=1;i<=n;i++)mn[i]=i/mn[i];
	sort(pl+1,pl+n+1,[](int i,int j){return mn[i]<mn[j];});
	for(int i=2;i<=n;i++)cout<<mn[pl[i]]<<' ';
}