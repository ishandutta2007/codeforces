#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
struct E{
	int v,id;
}e[505];
int n,m;
char str[505];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)str[j]='0'+(i==j);
		cout<<"? "<<str+1<<endl;
		int ret;
		cin>>ret;
		e[i].id=i,e[i].v=ret;
	}
	sort(e+1,e+m+1,[](E x,E y){return x.v<y.v;});
	int ans=0;
	for(int i=1,lst=0;i<=m;i++){
		for(int j=1;j<=m;j++)str[j]='0';
		for(int j=1;j<=i;j++)str[e[j].id]++;
		cout<<"? "<<str+1<<endl;
		int ret;
		cin>>ret;
		if(ret==lst+e[i].v)ans+=e[i].v;
		lst=ret;
	}
	cout<<"! "<<ans<<endl;
}