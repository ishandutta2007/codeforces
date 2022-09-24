#include<bits/stdc++.h>
using namespace std;
int q,cnt=0;
int main(){
	//int sum=0,s2=0;
	//for(int i=0;i<30;i+=2)sum+=(1<<i);
	//for(int i=0;i<30;i++)s2+=(1<<i);
	//cout<<sum<<' '<<s2<<endl;
	cin>>q;
	while(q--){
		//f.clear();
		int x,y;
		cin>>x>>y;
		if(y<x){
			puts("NO");
			continue;
		}
		bool flag=1;
		for(int i=0,sum=0;i<30;i++){
			if(x&(1<<i))sum++;
			if(y&(1<<i))sum--;
			if(sum<0)flag=0;
		}
		if(flag)puts("YES");
		else puts("NO");
		//if(dfs(x,y))puts("YES");
		//else puts("NO");
	}
}