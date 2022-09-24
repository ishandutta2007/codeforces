#include<bits/stdc++.h>
using namespace std;
int n,a[100005],cnt[100005];
int main(){
	int oo;
	cin>>oo;
	while(oo--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bool f=0;
		for(int j=29;j>=0;j--){
			int c1=0,c2;
			for(int i=1;i<=n;i++)if(a[i]&(1<<j))c1++;
			c2=(n-c1)%2;
			if(!c2){
				if(c1%2==0)continue;
				if(c1%4==1){
					puts("WIN");
					f=1;
					break;
				}
				if(c1%4==3){
					puts("LOSE");
					f=1;
					break;
				}
			}
			else {
				if(c1%2==1){
					puts("WIN");
					f=1;
					break;
				}
			}
		}
		if(!f)puts("DRAW");
	}
}