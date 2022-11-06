#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n){
		int s=0,t=0;
		for(int i=0;i<n;++i){
			int x,y;
			cin>>x>>y;
			if(x<0)++s;
			else ++t;
		}
		if(s>1&&t>1)puts("No");
		else puts("Yes");
	}
}