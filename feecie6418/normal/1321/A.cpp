#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
int a[105],b[105],n,c[105],s,t;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		if(a[i]&&!b[i])s++;
	}
	if(!s)return puts("-1"),0;
	for(int i=1;i<=n;i++)if(b[i]&&!a[i])t++;
	cout<<(t+s)/s;
}