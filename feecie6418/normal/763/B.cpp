#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
	cin>>n;
	puts("YES");
	for(int i=1;i<=n;i++){
		int x,y,z,w;
		scanf("%d%d%d%d",&x,&y,&z,&w);
		printf("%d\n",1+(x+1000000000)%2+(y+1000000000)%2*2);
	}
}